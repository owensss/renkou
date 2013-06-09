TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate\
    MainWindow \
    MainWindow

evaluate.depends = Scheme

