#ifndef FILEINFO_H
#define FILEINFO_H

//Map FileInfo 的结构  Add on 2011.009.17 by TP
struct FileInfo{
    QString m_FileName;
    int m_index;

    FileInfo(){
        m_FileName = "";
        m_index = -1;
    }
};

#endif // FILEINFO_H
