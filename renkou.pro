TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate

evaluate.depends = Scheme

