# $NetBSD: Makefile,v 1.13 2004/01/20 19:56:09 airhead Exp $
#

.include "./Makefile.common"

PKGNAME=        elvis-2.2.0
COMMENT=	Vi clone with regex search, hex editing, HTML and TeX previewing

PLIST_SRC=	${.CURDIR}/../../elvis/PLIST.common
PATCHDIR=	${.CURDIR}/../../elvis/patches
DISTINFO_FILE=	${.CURDIR}/../../elvis/distinfo

CONFLICTS+=	elvis-x11[0-9]*

CONFIGURE_ARGS+=	--with-x=no

.include "../../mk/bsd.pkg.mk"
