# $NetBSD: Makefile,v 1.4 2004/05/10 22:11:45 johnrshannon Exp $
#

DISTNAME=		gdb-${GDB_VERSION}
CATEGORIES=		wip
MASTER_SITES=		ftp://sources.redhat.com/pub/gdb/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		ftp://sources.redhat.com/pub/gdb/releases/
COMMENT=		The GNU Project Debugger

# OPTIONS
USE_GCC_3.4=		# defined

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=         make
USE_MAKEINFO=		YES
USE_NEW_TEXINFO=	YES

GDB_VERSION=	6.1
GDB_PREFIX=	${PREFIX}/${PKGNAME_NOREV}
INFO_DIR=	${GDB_PREFIX}/info
LIB_DIR=	${GDB_PREFIX}/lib
CONFIGURE_ARGS+=	--prefix=${GDB_PREFIX}
CONFIGURE_ARGS+=	--exec-prefix=${GDB_PREFIX}
CONFIGURE_ARGS+=	--infodir=${INFO_DIR}
CONFIGURE_ARGS+=	--libdir=${LIB_DIR}
CONFIGURE_ARGS+=	--includedir=${GDB_PREFIX}/include
CONFIGURE_ARGS+=	--mandir=${GDB_PREFIX}/man
CONFIGURE_ARGS+=	--datadir=${GDB_PREFIX}/share
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--without-included-gettext

pre-patch:
	${CP} files/nbsd-nat.c ${WRKSRC}/gdb

.if defined(USE_GCC_3.4)
pre-configure:
.include "../../wip/gcc-3.4/preconfigure.mk"
.endif

.if defined(USE_GCC_3.4)
.include "../../wip/gcc-3.4/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
