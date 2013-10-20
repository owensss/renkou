TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate \
    test \
    ui

evaluate.depends = Scheme
test.depends = test Scheme
