#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QTextCodec>
#include <iostream>
#include <QDebug>
#include "../Scheme/SchemeBuffer.hpp"
#include "../Scheme/Scheme.hpp"
#include "../Scheme/ConfigMan.hpp"
#include "../Scheme/schememetadata.h"
#include "../Scheme/SchemeInstance.hpp"
#include "../Scheme/exceptions/ColumnNotExist.hpp"
#include "../Scheme/exceptions/ValueNotExist.hpp"
#include "../Scheme/AbstractScheme.hpp"
#define dbtest(scheme, row, col) qDebug() << scheme->toInternalName() << "row " << row << "col" << col << scheme->getInstance(row)[col];

class TestTest : public QObject
{
        Q_OBJECT
        
    public:
        TestTest();
        
    private Q_SLOTS:
        void initTestCase();
        void cleanupTestCase();
        void testSchemeBuffer();
        void testAbstractScheme();
        void testScheme();
};

TestTest::TestTest()
{
}

void TestTest::initTestCase()
{
}

void TestTest::cleanupTestCase()
{
}

void TestTest::testAbstractScheme()
{
try {
    AbstractScheme as(std::make_shared<SchemeParameterDefault>(), std::make_shared<SchemeBuffer>());
    schememetadataPtr meta_renkougaiyao(new schememetadata("META_RENKOUGAIYAO"));
    as.set("diqu", QObject::tr("上海"));
    as.set("huji", QObject::tr("农业"));
    as.set("shixian", QObject::tr("回归生育"));
    as.set("duiji", QObject::tr("分释"));
    as.set("hunpei", QObject::tr(""));
    as.set("koujinplusshiji", QObject::tr("农d11"));
    as.set("qianyi", QObject::tr("非d11_z"));

    SchemePtr schemePtr = as.generate(meta_renkougaiyao);

    qDebug() << "name" << schemePtr->getName() << endl;

    schemePtr->getBuffer()->forceRead(schemePtr.get());
    QVERIFY2(true, "Failure");
    } catch (const ValueNotExist& e) {
        qDebug() << "value not exist at" << e.value();
    }
    catch(const RecordNotExist& e){
        qDebug() << "Record not exist at" << e.name();
    }
}
void TestTest::testSchemeBuffer()
{
    using Config::config;
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
     if (! config.read()) {
         std::cerr << "config not found!\n";
         exit(0);
     }

     // QTextCodec::setCodecForTr(utf8);
     // QTextCodec::setCodecForCStrings(utf8);

     std::shared_ptr<schememetadata> meta( new schememetadata(QString("META_RENKOUGAIYAO")) );
     std::shared_ptr<schememetadata> meta1( new schememetadata(QString("META_FUFUZINV")));
     std::shared_ptr<SchemeBuffer> buffer(new SchemeBuffer);
     // config.read("E:/renkou/sourcecode/evaluate_by_owensss/config.txt");
     //    qDebug() << "error!";
     //    return -1;
     // }
     SchemePtr test(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p15_非d11p15_z"));
     SchemePtr test1(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p20_非d11p20_z"));
     SchemePtr test2(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p25_非d11p25_z"));
     SchemePtr test3(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p30_非d11p30_z"));
     SchemePtr test4(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p35_非d11p35_z"));
     SchemePtr test5(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p40_非d11p40_z"));
     SchemePtr test6(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p45_非d11p45_z"));
     SchemePtr test7(new Scheme(meta, buffer, "安徽城镇人口概要_回归分释_多龄_农d11p15_非d11p15_z"));
     SchemePtr test8(new Scheme(meta, buffer, "安徽城镇人口概要_回归分释_多龄_农d11p20_非d11p20_z"));

     SchemePtr test_(new Scheme(meta1, buffer, "上海农业夫妇子女_回归分释_多龄_农d11p15_非d11p15_z"));
     SchemePtr test1_(new Scheme(meta1, buffer, "上海农业夫妇子女_回归分释_多龄_农d11p20_非d11p20_z"));
     SchemePtr test2_(new Scheme(meta1, buffer, "上海农业夫妇子女_回归分释_多龄_农d11p25_非d11p25_z"));
     SchemePtr test3_(new Scheme(meta1, buffer, "上海农业夫妇子女_回归分释_多龄_农d11p30_非d11p30_z"));
     SchemePtr test4_(new Scheme(meta1, buffer, "上海农业夫妇子女_回归分释_多龄_农d11p35_非d11p35_z"));
     SchemePtr test5_(new Scheme(meta1, buffer, "上海农业夫妇子女_回归分释_多龄_农d11p40_非d11p40_z"));
     SchemePtr test6_(new Scheme(meta1, buffer, "上海农业夫妇子女_回归分释_多龄_农d11p45_非d11p45_z"));
     SchemePtr test7_(new Scheme(meta1, buffer, "安徽城镇夫妇子女_回归分释_多龄_农d11p15_非d11p15_z"));
     SchemePtr test8_(new Scheme(meta1, buffer, "安徽城镇夫妇子女_回归分释_多龄_农d11p20_非d11p20_z"));

     qDebug() << test->getMetadata()->rowCount() << meta->rowSize() << meta->size();
     qDebug() << meta->startYear() << meta->endYear();
     qDebug() << meta->colCount() << meta->name();
     try {

     qDebug() << meta->rowSize()<<meta->colSize (1)<<meta->rowCount ();
     qDebug() <<meta->colCount ()<<meta->colAt (2).getindicator ()
              <<meta->colAt (QString("总人口")).getfield_name ()<<meta->colOffset (5)
              <<meta->operator[](2).getfield_dec ();
     // qDebug() << &(*meta) << &(*buffer);
     // <<meta->hasCol(999) << meta->hasRow (2550);

     // for (int i = 1; i<=meta->colCount(); ++i)
     qDebug() << "name" << test->getName();
     qDebug() << test->getInstance(2013).getString(2);
     dbtest(test,  2014, 115);
     dbtest(test1, 2014, 113);
     dbtest(test2, 2014, 115);
     dbtest(test3, 2014, 115);
     dbtest(test4, 2014, 115);
     dbtest(test5, 2014, 115);
     dbtest(test6, 2014, 115);
     dbtest(test7, 2014, 115);
     dbtest(test8, 2014, 115);
     dbtest(test4, 2014, 115);
     dbtest(test5, 2014, 115);
     /**/

     qDebug() << "name" << test_->getName();
     qDebug() << test_->getInstance(2013).getString(2);
     qDebug() << test_->getInstance(2014)[3];
     qDebug() << test1_->getInstance(2014)[30];
     qDebug() << test2_->getInstance(2014)[30];
     qDebug() << test3_->getInstance(2014)[30];
     qDebug() << test4_->getInstance(2014)[3];
     qDebug() << test5_->getInstance(2014)[3];
     qDebug() << test6_->getInstance(2014)[3];
     qDebug() << test7_->getInstance(2014)[3];
     qDebug() << test8_->getInstance(2014)[3];
     qDebug() << test4_->getInstance(2014)[3];
     qDebug() << test5_->getInstance(2014)[3];
     // qDebug() << test7->getInstance(2014)[3];

     qDebug() << "name" << test->getName();
     qDebug() << test->getInstance(2013).getString(2);
     dbtest(test,  2014, 115);
     dbtest(test1, 2014, 113);
     dbtest(test2, 2014, 115);
     dbtest(test3, 2014, 115);
     dbtest(test4, 2014, 115);
     dbtest(test5, 2014, 115);
     dbtest(test6, 2014, 115);
     dbtest(test7, 2014, 115);
     dbtest(test8, 2014, 115);
     dbtest(test4, 2014, 115);
     dbtest(test5, 2014, 115);
     /**/
     qDebug() << "done";
     } catch (const ValueNotExist&e) {
         qDebug() << e.value();
     } catch (const ColNotExist& e) {
         qDebug() << e.value() << e.index();
     } catch (const RecordNotExist& e) {
         qDebug() << "record not exist" << e.name();
     }
    QVERIFY2(true, "Failure");
}

void TestTest::testScheme() {
    using Config::config;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    if (! config.read()) {
        std::cerr << "config not found!\n";
        exit(0);
    }

    // QTextCodec::setCodecForTr(utf8);
    // QTextCodec::setCodecForCStrings(utf8);

    std::shared_ptr<schememetadata> meta( new schememetadata(QString("META_RENKOUGAIYAO")) );
    std::shared_ptr<schememetadata> meta1( new schememetadata(QString("META_FUFUZINV")));
    std::shared_ptr<SchemeBuffer> buffer(new SchemeBuffer);

    SchemePtr test(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p15_非d11p15_z"));
    SchemePtr test2(new Scheme(meta, buffer, "K:\\demography\\data\\sim\\0926\\上海农业人口概要_回归分释_多龄_农d11p15_非d11p15_z"));
    SchemePtr test3(new Scheme(meta, buffer, "上海农业人口概要_回归分释_多龄_农d11p15_非d11p15_z.txt"));
    SchemePtr test4(new Scheme(meta, buffer, "K:\\demography\\data\\sim\\0926\\上海农业人口概要_回归分释_多龄_农d11p15_非d11p15_z.txt"));

    try {
        qDebug() << "internal " << test->toInternalName();
        dbtest(test,  2014, 12);
        qDebug() << "internal " << test2->toInternalName();
        dbtest(test2,  2014, 12);

        dbtest(test3,  2014, 115);
        dbtest(test4,  2014, 115);
    } catch (const ValueNotExist&e) {
        qDebug() << e.value();
    } catch (const ColNotExist& e) {
        qDebug() << e.value() << e.index();
    } catch (const RecordNotExist& e) {
        qDebug() << "record not exist" << e.name();
    }
}

QTEST_MAIN(TestTest)

#include "tst_testtest.moc"
