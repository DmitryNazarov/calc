CONFIG += console c++11
QT =

INCLUDEPATH += "../../gtest/include"
INCLUDEPATH += "../../gtest"
INCLUDEPATH += "../../Calc/Calc"

SOURCES += \
    ../../gtest/src/gtest.cc \
    ../../gtest/src/gtest-all.cc \
    ../../gtest/src/gtest-death-test.cc \
    ../../gtest/src/gtest-filepath.cc \
    ../../gtest/src/gtest-port.cc \
    ../../gtest/src/gtest-printers.cc \
    ../../gtest/src/gtest-test-part.cc \
    ../../gtest/src/gtest-typed-test.cc \
    calcTests.cpp

HEADERS += \
    ../../gtest/include/internal/gtest-death-test-internal.h \
    ../../gtest/include/internal/gtest-filepath.h \
    ../../gtest/include/internal/gtest-internal.h \
    ../../gtest/include/internal/gtest-linked_ptr.h \
    ../../gtest/include/internal/gtest-param-util-generated.h \
    ../../gtest/include/internal/gtest-param-util.h \
    ../../gtest/include/internal/gtest-port.h \
    ../../gtest/include/internal/gtest-string.h \
    ../../gtest/include/internal/gtest-tuple.h \
    ../../gtest/include/internal/gtest-type-util.h \
    ../../gtest/include/gtest-death-test.h \
    ../../gtest/include/gtest-message.h \
    ../../gtest/include/gtest-param-test.h \
    ../../gtest/include/gtest-printers.h \
    ../../gtest/include/gtest-spi.h \
    ../../gtest/include/gtest-test-part.h \
    ../../gtest/include/gtest-typed-test.h \
    ../../gtest/include/gtest.h \
    ../../gtest/include/gtest_pred_impl.h \
    ../../gtest/include/gtest_prod.h \
    ../../Calc/Calc/calc.h
