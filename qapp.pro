TEMPLATE = app
SOURCES = qapp.cc

HEADERS = thread.h

CONFIG += qt link_pkgconfig
CONFIG -= app_bundle

QT += gui widgets

PKGCONFIG += glib-2.0
