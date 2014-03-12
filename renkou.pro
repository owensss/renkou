<<<<<<< HEAD
=======

>>>>>>> f7bbdfeec132428a546966e8f5919d9479f7f366
TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Scheme\
    evaluate \
    test \
    ui

evaluate.depends = Scheme
<<<<<<< HEAD
test.depends = test Scheme
=======
test.depends = test
>>>>>>> f7bbdfeec132428a546966e8f5919d9479f7f366
