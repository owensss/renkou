TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate\
    test
evaluate.depends = Scheme
test.depends = test
