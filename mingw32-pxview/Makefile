# $NetBSD: Makefile,v 1.1.1.1 2003/12/01 04:23:26 mpasternak Exp $
#

DISTNAME=		pxview_0.1.4.orig
PKGNAME=		${MINGW_PKG_PREFIX}pxview-0.1.4
CATEGORIES=		databases
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/pxlib/
COMMENT=		Simple utility to view Paradox database files

WRKSRC=			${WRKDIR}/pxview-0.1.4
USE_PKGLOCALEDIR=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
MINGW_STATIC=		# defined

BUILD_DEPENDS=		${MINGW_PKG_PREFIX}pxlib>=0.2.0:../../wip/mingw32-pxlib

.include "../../wip/mk/win32.pkg.mk"
