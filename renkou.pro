TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate \
    test \
    ui

evaluate.depends = Scheme

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate\
    test
evaluate.depends = Scheme
test.depends = test
