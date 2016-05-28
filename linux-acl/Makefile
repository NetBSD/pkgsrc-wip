# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=		acl_2.2.39-1
PKGNAME=		linux-acl-2.2.39.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://oss.sgi.com/projects/xfs/cmd_tars/

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://acl.bestbits.at/
COMMENT=		The acl package contains the setfacl and getfacl utils

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*


AUTOCONF_REQD=	2.50

USE_TOOLS+=		autoconf gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

WRKSRC=		${WRKDIR}/acl-2.2.39

pre-configure:
	cd ${WRKSRC}; autoconf

do-build:
	cd ${WRKSRC}; gmake

do-install:
	cd ${WRKSRC}; gmake install install-lib install-dev

post-install:
	ln -sf ${PREFIX}/lib/libacl.so.* ${PREFIX}/libexec

.include "../../wip/linux-attr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
