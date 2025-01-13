#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    BitcoinExchange(const std::string& dbFile);
    float getExchangeRate(const std::string& date) const;
    void processInputFile(const std::string& inputFile) const;

private:
    std::map<std::string, float> database;

    void loadDatabase(const std::string& dbFile);
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
};

#endif
