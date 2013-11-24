#include "Scheme.hpp"
#include "evaluate.h"
#include "method_add.h"
#include "ConfigMan.hpp"
#include "SchemeBuffer.hpp"
#include "schememetadata.h"
#include "SchemeIndicator.hpp"
#include "exceptions/ColumnNotExist.hpp"
#include <cassert>
#include <boost/filesystem.hpp>
#include <QString>
#include <iostream>
#include <QObject>
#include <QDebug>
#include <QTextCodec>

// TODO: I Need A Record Manager!!!!
namespace {

	QString standarlize(const QString& value) {
		// remove meta info
		return QString(value).replace(QString("人口概要"), "").replace(QString("夫妇子女"), "");
	}

	void align(const std::vector<SchemePtr>& v1, std::vector<SchemePtr>& v2) {
		size_t ssize = v1.size();
		size_t tsize = v2.size();
		assert(ssize == tsize);
		bool found = false;
		for (size_t i = 0; i < ssize; ++i) {
			QString name = standarlize(v1[i]->getName());
			found = false;
			std::cerr << "rkgy " << v1[i]->getName().toStdString();
			for (size_t j = 0; j < tsize; ++j) {
				if (standarlize(v2[j]->getName())==name) {
					found = true;
					std::swap(v2[i], v2[j]);
					std::cerr << ", ffzn " << v2[i]->getName().toStdString() << std::endl;
					break;
				}
			}
			assert(found);
		}
	}

}

// bool get_choice(int argc, const char* argv[], bool* swt);
// @input: 110, 010 .etc
// 	=> add  ? 1:0
// 	=> mult ? 1:0
// 	=> var  ? 1:0
int main (int argc, const char* argv[]) {

	using namespace std;
	try {
		// force use utf-8
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

		bool swt[3]; // add, mult, var
		swt[0] = false; swt[1] = false; swt[2] = false; // init
		// if (! get_choice(argc, argv, swt)) return -1;
        if(!Config::config.read())
        {
            std::cerr<<"config not found!\n";
            exit(0);
        }
		cerr << "gao1 " << endl;
		schememetadataPtr meta_rkgy(new schememetadata(QString("META_RENKOUGAIYAO")));
		schememetadataPtr meta_fufuzinv(new schememetadata(QString("META_FUFUZINV")));
		cerr << "gao2" << endl;
		cerr << "start" << meta_rkgy->startYear() << "end" << meta_rkgy->endYear() << endl;
		std::vector<SchemePtr> v_rkgy;
		std::vector<SchemePtr> v_ffzn;

		SchemeBufferPtr buffer(new SchemeBuffer());

		namespace bf=boost::filesystem;

		cerr << "I am gao\n" ;
		cerr << Config::config["DATA_PATH"].toStdString() << endl;

		bf::path path(Config::config["DATA_PATH"].toStdString());
		bf::directory_iterator end_iter;

        auto gbk = QTextCodec::codecForName("gbk");
        auto gbk_dec = gbk->makeDecoder();
		for (bf::directory_iterator file_iter(path); file_iter != end_iter; ++file_iter) {
            auto filename = gbk_dec->toUnicode(file_iter->path().filename().string().c_str());
            // qDebug() << "ori filename" << file_iter->path().filename().string().c_str();
			// remove ".txt"
            filename.remove(".txt").remove(".TXT");
            if (filename.contains("浙北")) {
                if (filename.contains("合计人口概要")) {
                    qDebug() << "filename" << filename;
                    v_rkgy.push_back(std::make_shared<Scheme>(Scheme(meta_rkgy, buffer, filename)));
					buffer->forceRead(v_rkgy.back().get());
                } else if (filename.contains("合计夫妇子女")) {
                    qDebug() << "filename" << filename;
                    v_ffzn.push_back(std::make_shared<Scheme>(Scheme(meta_fufuzinv, buffer, filename)));
					buffer->forceRead(v_ffzn.back().get());
				}
			}
		}

        // v_rkgy.push_back(SchemePtr( new Scheme(meta_rkgy, buffer, QString("上海合计人口概要_回归分释_多龄_农d11p15_非d11p15_z"))));
		// v_ffzn.push_back(SchemePtr( new Scheme(meta_fufuzinv, buffer, QString("上海合计夫妇子女_回归分释_多龄_农d11p15_非d11p15_z"))));
		// align(v_rkgy, v_ffzn);
        std::cerr << "gaohaole\n";
		std::vector<std::vector<SchemePtr>> c;
		c.push_back(v_rkgy);
		c.push_back(v_ffzn);
		auto r = method_add(c);
		/*
		 *	struct evaluate_result {
		 score_type synthesize;
		 score_type rule_1[4];
		 score_type rule_2[9];
		 score_type indicator[15]; // 15
		 SchemePtr scheme;
		 };
		 */
        sort(&r[0], &r[v_rkgy.size()],
                [&](const METHOD_ADD::evaluate_result& lhs, const METHOD_ADD::evaluate_result& rhs)
                {
                    return lhs.synthesize > rhs.synthesize;
                }
        );
		for (size_t j = 0; j < v_rkgy.size(); ++j) {
			qDebug() << r[j].scheme->getName();
			qDebug() << "indicator";
			for (int i = 0 ; i < 15; ++i)
				qDebug() << r[j].indicator[i];
			qDebug() << "rule2";
			for (int i = 0 ; i < 9; ++i)
				qDebug() << r[j].rule_2[i];
			qDebug() << "rule1";
			for (int i = 0 ; i < 4; ++i)
				qDebug() << r[j].rule_1[i];
			qDebug() << r[j].synthesize;
			// if (swt[1]) method_mult();
			// if (swt[2]) method_var();
		}
		delete r;

	} catch (const exception& e) {
		cerr << "error";
	} catch (int ) {
		cerr << "int";
	} catch (const InstanceIndexOutOfRange& e) {
		qDebug() << e.what()->toInternalName() << e.index();
	} catch (const ColNotExist& e) {
		qDebug() << e.index() << e.value();
    } catch (const RecordNotExist& e ) {
        qDebug() << "record not exist" << e.name();
    }

	// } catch (const ColNotExist& e) {
	//    cerr << e.value().toStdString() << e.index();
	// }
}

bool get_choice(int argc, const char* argv[], bool* swt) {
	if (argc != 2) return false;
	int len = strlen(argv[1])<3 ? strlen(argv[1]) : 3;
	for (int i = 0; i < len; ++i)
		swt[i] = argv[i]-'0';
}
