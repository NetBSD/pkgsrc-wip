# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=		attr_2.4.32-1
PKGNAME=	linux-attr-2.4.32.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://oss.sgi.com/projects/xfs/cmd_tars/

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://acl.bestbits.at/
COMMENT=		The extended attribute package for acl

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*


AUTOCONF_REQD=	2.50

USE_TOOLS+=		autoconf gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

WRKSRC=		${WRKDIR}/attr-2.4.32

pre-configure:
	cd ${WRKSRC}; autoconf

do-build:
	cd ${WRKSRC}; gmake

do-install:
	cd ${WRKSRC}; gmake install install-lib install-dev

post-install:
	ln -sf ${PREFIX}/lib/libattr.so.* ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
