## Process this file with automake to produce Makefile.in

# disk
diskdir = $(PLUGIN_PATH)

disk_LTLIBRARIES = disk.la

disk_la_SOURCES = \
	disk_main.c

disk_la_CFLAGS = -I$(top_srcdir)/include -I$(srcdir)/../../common \
	-I$(srcdir)/.. -DPLUGIN_PATH=\"$(PLUGIN_PATH)\"

disk_la_LDFLAGS = -avoid-version -module

disk_la_LIBADD = ../../common/libcommon.la

# extra
EXTRA_DIST =

DISTCLEANFILES = 

