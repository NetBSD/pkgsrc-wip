# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:37 thomasklausner Exp $

DISTNAME=	${VERS}
PKGNAME=	megaglest-${VERS}
PKGREVISION=	1
VERS=		3.9.1
CATEGORIES=	games
MASTER_SITES=	https://github.com/MegaGlest/megaglest-source/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://megaglest.org/
COMMENT=	Cross-platform 3D real-time-strategy game with seven factions
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/megaglest-source-${VERS}
USE_TOOLS+=	cmake bash autoconf automake pkg-config
REPLACE_BASH=	build-mg.sh
USE_LANGUAGES=	c c++

EXTRACT_USING=	bsdtar

#Does not extract clean by itself. Upon fail, extract manually, uncomment
#this, and make again.
#do-extract:

do-build:
	cd ${WRKSRC} && ./build-mg.sh

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/ftgl/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
