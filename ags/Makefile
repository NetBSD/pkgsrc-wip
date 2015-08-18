# $NetBSD: Makefile,v 1.1 2015/08/18 18:47:57 yhardy Exp $

GITHUB_PROJECT=	ags
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-3.3.4.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=adventuregamestudio/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v.${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adventuregamestudio.co.uk/
COMMENT=	Adventure Game Studio runtime engine
LICENSE=	artistic-2.0

WRKSRC=		${WRKDIR}/ags-v.3.3.4.1
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} --directory=Engine

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Engine/ags ${DESTDIR}${PREFIX}/bin/

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../wip/dumb/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
