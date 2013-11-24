#ifndef _CONFIG_MAN_HPP
#define _CONFIG_MAN_HPP
#include <QMap>
#include <QString>

/**
 * aim: I shall make the program run normally evenif config is not loaded
 * usage:
 * 1, Decalare:
 * 		ConfigMan config;
 * 2, read Configure file
 * 		config.read("config.txt");
 * 	2.1, validate:
 * 		if (config.read())
 * 			or
 * 		config.read();
 * 		if (config.success());
 * 3, read value:
 * 		config.value("startYear")
 */
namespace Config {

    class ConfigMan {
        public:
            ConfigMan() {valid = false;}
            ~ConfigMan(void) {}
            // read config file, reture false upon failure
            bool read(const QString& _filename="K:\\build-renkou-Desktop_Qt_5_1_1_MinGW_32bit-Debug\\config.txt") ;
            // return true if config file is read
            bool success(void) const { return valid; }
            // throw ValueNotExist
            const QString& value(const QString& key) const;
            const QString& operator [] (const QString& key) const {return value(key);}
            // do no effort to prevent users from reading wrong format
            int Int(const QString& key) const {return value(key).toInt();}
            double Double(const QString& key) const {return value(key).toDouble();}
        private:
                QString __filename;
                bool valid;
                QMap<QString, QString> map;
    } ;

    // the default instance
    // you can decalare your own configman
    extern ConfigMan config;
};

#endif
