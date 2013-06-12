#include <QString>
#include <QtTest>

#include <QObject>
#include <QDebug>
#include <memory>
#include "exceptions/ValueNotExist.hpp"
#include "..\Scheme\AbstractScheme.hpp"
#include "..\Scheme\SchemeParameter.hpp"
#include "..\Scheme\Scheme.hpp"

class TestTest : public QObject
{
    Q_OBJECT
    
public:
    TestTest();
    
private Q_SLOTS:
    void testCase1();
};

TestTest::TestTest()
{
    Config::config.read();
}

void TestTest::testCase1()
{   try {
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

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
