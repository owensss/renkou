#ifndef _SCHEME_PARA_HPP
#define _SCHEME_PARA_HPP
#include <QString>
#include "SchemeDef.hpp"
#include "schememetadata.h"
#include "parasetter.hpp"
#include "paraholder.hpp"

/* this class provide an interface the set the scheme parameter &
 * translate it into a true scheme name
 */
/*
 * note: 为了保证以后可能从文件中读取参数，该类必须是运行时多态的。so you are not permitted to use a template. don't you
 *       this class shall be runtime-Polymorphism to ensure the ability to read parameters from the config file
 */
class SchemeParameter : public ParaSetter {
    public:
        /* @desc: the non-virtual function for call
         * @impl: calls do_generate and some extra, common work(if any)
         */
        SchemeParameter(std::shared_ptr<ParaHolder> hd) :ParaSetter(hd) {}
        virtual ~SchemeParameter() {}
        QString generate(schememetadataPtr meta) const ;
    private:
        /* @desc: the pure-virtual function than does the real thing
         * @params: the parameters input, the metadata
         * @return: the internal scheme name (used by Abstract Scheme)
         * @note: the full name of a scheme will be determined by the metadata
         */
        virtual QString do_generate(schememetadataPtr meta) const = 0;
};

class SchemeParameterDefault : public SchemeParameter{
    public:
        explicit SchemeParameterDefault();
/* *************** @ 尹老师 聊天记录(From QQ @conversation with Yin.)
         地区、政策实现程度（分两种：政策生育、可能生育，可能生育即原来的“回归生育”）、堆积释放模式（分四种：分释、突释、缓释、正常）、婚配概率估计方法（只有多龄概率一种，可不标明。原来还有同龄概率）、户籍（农业、非农）、政策口径(多种)+政策调整时机、迁移强度
 * *****************************************************************/
        /*
         * @note: for convention, all array inputs(Caliber, Timing. etc) shall be input in only one parameter, and the value shall be seperated by ':'
         * @params: 地区, 实现程度, 堆积释放, 婚配概率估计法, 户籍, 政策口径, 调整时机, 迁移强度
         */
        // bool setValue(const QString& diqu, const QString& shixian, const QString& duiji, const QString& hunpei, const QString& huji, const QString& koujin, const QString& shiji, const QString& qianyi);
        /* note: must call the process before any instantial*/
        static void init(void);
    private:
        virtual QString do_generate(schememetadataPtr meta) const;
        static std::shared_ptr<ParaHolder> paraholder;
};

#endif
