<<<<<<< HEAD
TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate \
    test \
    ui

evaluate.depends = Scheme

=======
TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate\
    MainWindow
    test
evaluate.depends = Scheme
test.depends = test
>>>>>>> upstream/master
