#include "SchemeParameter.hpp"
#include <QObject>

std::shared_ptr<ParaHolder> SchemeParameterDefault::paraholder =
std::make_shared<ParaHolder>(ParaHolder{"diqu", "shixian", "duiji", "hunpei", "huji", "koujinplusshiji", "qianyi"});

QString SchemeParameter::generate(schememetadataPtr meta) const {
    return do_generate(meta);
}

SchemeParameterDefault::SchemeParameterDefault(std::shared_ptr<ParaHolder> /* hd */)
    :SchemeParameter(paraholder)
{

}

void SchemeParameterDefault::init(void) {
    if (! paraholder) paraholder = std::make_shared<ParaHolder>(ParaHolder());
}

QString SchemeParameterDefault::do_generate(schememetadataPtr meta) const {

    if (meta->name() == "META_RENKOUGAIYAO") {
        /* 上海农业人口概要_回归分释_多龄_农d11p15_非d11p15_z */
        return (
                    value("diqu")+
                value("huji")+
                QString("人口概要")+
                "_"+
                QString(value("shixian")).remove(QString("生育"))+
                value("duiji")+
                "_"+
                value("hunpei") == "" ? QString("多龄") : value("hunpei")+ // default value
                "_"+
                value("koujinplusshiji")+
                value("qianyi")
        );
    }
    return "";
    // TODO: return statement
}
