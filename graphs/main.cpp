#include <QtCore>
#include <QApplication>
#include <QTextCodec>
#include <QDebug>
#include "FileInfo.h"
#include "linetype1.h"
#include "linetype2.h"
#include "linetype3.h"
#include "Scheme.hpp"
#include "SchemeInstance.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    using Config::config;
//    if( !config.read()){
//        qDebug()<<"config file not exist";
//    }

//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    int start_year = 2010;
    int end_year = 2130;
    QVector<QString> curves;
    curves.push_back(QObject::tr("北京农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    curves.push_back(QObject::tr("辽宁农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    curves.push_back(QObject::tr("浙江农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    curves.push_back(QObject::tr("上海农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    curves.push_back(QObject::tr("湖南农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    curves.push_back(QObject::tr("湖北农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    curves.push_back(QObject::tr("云南农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    curves.push_back(QObject::tr("山西农业_现行_非农业_现行回归估计2010全员婚配有偶中迁移合计多龄概率分释模式"));
    QVector<FileInfo> files;
    FileInfo f1;
    // f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/北京合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_FileName = QObject::tr("北京合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_index = 92;
    files.push_back(f1);

    // f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/辽宁合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_FileName = QObject::tr("辽宁合计人口概要_回归分释_多龄_农X行_非X行_Z");
    f1.m_index = 92;
    files.push_back(f1);

    f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/浙江合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
//    f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/浙江合计人口概要_回归分释_多龄_农X行_非X行_Z");
    f1.m_index = 92;
    files.push_back(f1);

    // f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/上海合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_FileName = QObject::tr("上海合计人口概要_回归分释_多龄_农X行_非X行_Z");
    f1.m_index = 92;
    files.push_back(f1);

    // f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/湖南合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_FileName = QObject::tr("湖南合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_index = 92;
    files.push_back(f1);
    // f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/湖北合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_FileName = QObject::tr("湖北合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_index = 92;
    files.push_back(f1);

    // f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/云南合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_FileName = QObject::tr("云南合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_index = 92;
    files.push_back(f1);

    // f1.m_FileName = QObject::tr("I:/生育政策演示/生育政策仿真结果文件0926/山西合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_FileName = QObject::tr("山西合计人口概要_回归分释_多龄_农X行_非X行_Z.TXT");
    f1.m_index = 92;
    files.push_back(f1);

    QWidget* l = LineType3::makeLineType3(curves, files, start_year, end_year);
    l->show();


//    //汉字支持
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

//    std::shared_ptr<schememetadata> meta;
//    if(files.front().m_FileName.contains(QObject::tr("夫妇子女")))
//    {
//        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_FUFUZINV")));
//    }
//    else if(files.front().m_FileName.contains(QObject::tr("人口概要")))
//    {
//        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_RENKOUGAIYAO")));
//    }
//    else if(files.front().m_FileName.contains(QObject::tr("生育孩次")))
//    {
//        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_SHENGYUHAICI")));
//    }
//    else //if(files.front().m_FileName.contains(QObject::tr("政策生育")))
//    {
//        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_ZHENGCESHENGYU")));
//    }

//    std::shared_ptr<SchemeBuffer> buffer(new SchemeBuffer);

//    try{
//        for(int i=0; i<files.size(); ++i){
//            QString filename = files[i].m_FileName.section('/', -1).section('.', 0 ,0);
//            qDebug()<<"main()"<<filename;
//            SchemePtr ptr(new Scheme(meta, buffer, filename));
//            for(int j=start_year; j<=end_year; ++j){
//                double num = ptr->getInstance(j)[files[i].m_index];
//                qDebug()<<num;
//            }
//        }
//    }
//    catch(const RecordNotExist& e){
//        qDebug() << "Record not exist at" << e.name();
//    }

    return a.exec();
}
