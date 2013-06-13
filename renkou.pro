TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate\
    MainWindow
    test
evaluate.depends = Scheme
test.depends = test
