# $NetBSD: Makefile,v 1.3 2012/11/01 03:49:17 asau Exp $
#

DISTNAME=	pink-pony-1.2.1
PKGNAME=	pinkpony-1.2.1
CATEGORIES=	games
MASTER_SITES=	http://pink-pony.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/pink-pony/
COMMENT=	Pink Pony is a 3D racing game with ponies!
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons

WRKSRC=		${WRKDIR}/pink-pony
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

FIND_PREFIX:=	SCONSDIR=scons

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ${SCONSDIR}/bin/scons prefix=${PREFIX}

do-install:

.include "../../graphics/glfw/buildlink3.mk"
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../wip/ftgl/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../wip/audiere/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../mk/find-prefix.mk"
.include "../../mk/bsd.pkg.mk"
