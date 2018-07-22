# $NetBSD: Makefile,v 1.2 2015/09/14 22:26:14 yhardy Exp $

DISTNAME=	ags-3.4.1.14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=adventuregamestudio/}
GITHUB_TAG=	v.${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adventuregamestudio.co.uk/
COMMENT=	Adventure Game Studio runtime engine
LICENSE=	artistic-2.0

WRKSRC=		${WRKDIR}/ags-${GITHUB_TAG}
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
