#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file " + dbFile);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, priceStr;
        if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) {
            float price = std::stof(priceStr);
            database[date] = price; // Insert into map
        }
    }
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    auto it = database.lower_bound(date);
    if (it == database.end() || it->first != date) {
        if (it != database.begin()) --it; // Go to the closest lower date
        else throw std::runtime_error("Error: no valid date found in the database.");
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Simple date validation (YYYY-MM-DD format)
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    try {
        value = std::stof(valueStr);
        return value >= 0 && value <= 1000;
    } catch (...) {
        return false;
    }
}

void BitcoinExchange::processInputFile(const std::string& inputFile) const {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(date.find_last_not_of(" \t") + 1); // Trim trailing spaces
            valueStr.erase(0, valueStr.find_first_not_of(" \t")); // Trim leading spaces

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            float value;
            if (!isValidValue(valueStr, value)) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            try {
                float rate = getExchangeRate(date);
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}
