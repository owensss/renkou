#include "metadataItem.h"
#include "schemeDef.hpp"
#include <string>
metadataItem::metadataItem(QString fname = "",
            QString ftype = "",
            int flen = 0,
            int fdec = 0,
            int findex = 0,
            QString findicator = ""
            )
        :field_name(fname),
            field_dec(fdec),
        index(findex)
{
    if(findicator == "")
    {
        indicator = field_name;
    }else indicator = findicator;

    if(ftype == "C"){
        field_type = STRING;
        field_len = flen; //STRING
    }

    else if(ftype == "N" && fdec == 0)
    {
        field_len = sizeof(schInt);
        field_type = INT; //INT
    }

    else
    {
        field_len = sizeof(schDouble);
        field_type = DOUBLE; //DOUBLE
    }
}

