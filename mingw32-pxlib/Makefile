# $NetBSD: Makefile,v 1.3 2003/12/01 04:25:09 mpasternak Exp $
#

DISTNAME=		pxlib_0.2.0.orig
PKGNAME=		${MINGW_PKG_PREFIX}pxlib-0.2.0
CATEGORIES=		databases devel
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		C language library for reading Paradox database files

WRKSRC=			${WRKDIR}/pxlib-0.2.0
USE_PKGLOCALEDIR=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pxlib.pc.in
GNU_CONFIGURE=		yes
MINGW_STATIC=		# defined

BUILD_DEPENDS=		${MINGW_PKG_PREFIX}libiconv>=1.9.1:../../wip/mingw32-libiconv

.include "../../wip/mk/win32.pkg.mk"
