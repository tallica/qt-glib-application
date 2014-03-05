TEMPLATE = app
SOURCES = qapp.cc

CONFIG += qt
CONFIG -= app_bundle

QT += gui widgets

CONFIG += link_pkgconfig
PKGCONFIG += glib-2.0
