VERSION=	2.1.19

# Path options
PREFIX?=	/usr/local
X11BASE?=	/nonexistent
INSTALLROOT?=	$(DESTDIR)$(PREFIX)
INSTALLDIR?=	$(INSTALLROOT)/bin
INCLUDEDIR?=	$(INSTALLROOT)/include
LOCALEDIR?=	$(INSTALLROOT)/share/locale
PKGCONFIGDIR?=	$(INSTALLROOT)/lib/pkgconfig
MANDIR?=	$(INSTALLROOT)/man/man1
SMANDIR?=	$(INSTALLROOT)/man/man1
SINSTALLDIR?=	$(INSTALLROOT)/bin

# Ownership and mode options
DATAMODE?=	0644
BINMODE?=	0755
BINOWNER?=	root
BINGROUP?=	root

# Tools paths
MSGFMT?=	msgfmt
MSGFMT_OPT?=	-f -v 
INSTALL?=	install
PKG_CONFIG?=	pkg-config
STRIP?=		-s

# Helpers
INSTALL_DIR=	$(INSTALL) -d
INSTALL_DATA=	$(INSTALL) -c -m $(DATAMODE)
INSTALL_BIN=	$(INSTALL) -c -m $(BINMODE) -o $(BINOWNER) -g $(BINGROUP)

# Compilation options
ENABLE_NLS?=	1

# OS-specific overrides
SUPPORTED_OSES=	Linux NetBSD FreeBSD OpenBSD Darwin Solaris

REALOPSYS=	$(shell uname -s)
OPSYS=		$(if $(findstring $(REALOPSYS),$(SUPPORTED_OSES)),$(REALOPSYS),Linux)
OSREV=		$(shell uname -r)

# Isn't this ugly?

ifeq ($(OPSYS),NetBSD)
SYS_LIBS=	-lkvm
BINGROUP=	kmem
else
 ifeq ($(OPSYS),OpenBSD)
SYS_LIBS=	-lkvm -pthread
BINGROUP=	kmem
 else
  ifeq ($(OPSYS),FreeBSD)
BINGROUP=	kmem
   ifeq ($(filter 2.%,$(OSREV)),)
SYS_LIBS=	-lkvm -ldevstat -lmd
   else
SYS_LIBS=	-lkvm -lmd
   endif
  else
   ifeq ($(OPSYS),Darwin)
SYS_LIBS=	-lkvm -lmd5 -framework IOKit
LINK_FLAGS+=	-flat_namespace -undefined warning -prebind -Wl,-bind_at_load
GTK_CONFIG=	gtk-config
STRIP=
    ifeq ($(MODULE),src)
CFLAGS+=	-Ddlsym=dlsym_prepend_underscore
    endif
   else
    ifeq ($(OPSYS),Solaris)
MSGFMT_OPT=	-v 
CC?=		gcc
CFLAGS+=	-Wno-implicit-int
SYS_LIBS=	-lkstat -lkvm -ldevinfo
     ifeq ($(OSREV),5.8)
LINK_FLAGS=
SYS_LIBS+=	-lsocket -lintl
      ifeq ($(MODULE),src)
SYS_LIBS+=	-lresolv -lX11
      else # Well, we don't really care about po
SYS_LIBS+=	-lnsl
CFLAGS+=	-DSOLARIS_8
      endif
     else
      ifeq ($(MODULE),src)
SYS_LIBS+=	-lresolv
      else
SYS_LIBS+=	-lsocket -lnsl
      endif
     endif
    endif
   endif
  endif
 endif
endif
