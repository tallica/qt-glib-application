TEMPLATE = app
SOURCES = qapp.cc glib_thread.cc

HEADERS = glib_thread.h

CONFIG += qt link_pkgconfig
CONFIG -= app_bundle

QT += gui widgets

PKGCONFIG += glib-2.0
