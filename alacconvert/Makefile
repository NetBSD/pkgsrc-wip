# $NetBSD: Makefile,v 1.1.1.1 2011/11/13 11:04:44 ryo-on Exp $
#

DISTNAME=	libalac-r3
PKGNAME=	alacconvert-3
CATEGORIES=	audio
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://alac.macosforge.org/
COMMENT=	Apple Lossless Audio Codec converter by Apple
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/libalac-r3/convert-utility
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile
BUILD_TARGET=	alacconvert

.include "../../wip/libalac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
