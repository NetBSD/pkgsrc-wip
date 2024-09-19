# make header file
# pathname variables
# =()<NEWSARTS=@<NEWSARTS>@>()=
NEWSARTS=@CNEWSARTS@
# =()<NEWSOV=@<NEWSOV>@>()=
NEWSOV=@CNEWSOV@
# =()<NEWSBIN=@<NEWSBIN>@>()=
NEWSBIN=@CNEWSBIN@
# =()<NEWSCTL=@<NEWSCTL>@>()=
NEWSCTL=@CNEWSCTL@
# =()<NEWSCONFIG=@<NEWSCONFIG>@>()=
NEWSCONFIG=@CNEWSCTL@/bin/config

# workaround for System V make bug
SHELL=/bin/sh

# directories where things go
UIBIN=@PREFIX@/bin
RBIN=@CNEWSBIN@

# compilation stuff
# LIB is for makefile dependencies, LIBS for cc invocations
LIB=../libcnews.a
LIBS=../libcnews.a 
CFLAGS=$(MORECFLAGS) @CNEWSCFLAGS@ -I../include
LDFLAGS=$(CFLAGS) 
LINTFLAGS=$(MORELINTFLAGS) -I../include

# directories etc.
CONF=../conf
MAKE=make
TO=$(CONF)/cpto
IN=$(CONF)/cmpto $(CMPOPT)
CF=$(CONF)/checkfile $(CMPOPT)
MKDIR=$(CONF)/mkdirs
MX=chmod +x
UPDATE=$(CONF)/update.sym ../libcnews.a
LIBCMP=$(CONF)/libcmp ../libcnews.a

# misc configuration bits
SPACEFOR=@CNEWSDFTYPE@
DOSPACEFOR=dospacefor
QUEUELEN=tay
UID=@CNEWSUID@
GID=@CNEWSGID@
SIZE=big
DBZ=libdbz
STDIO=sysstdio
SERVER=
REPORTTO=@CNEWSMASTER@
URGENTTO=@CNEWSMASTER@

# things for testing
HERE=. ../conf/rsetup ;

# fake files needed
HFAKE= sys/timeb.h
OFAKE= fgetline.o fsync.o
