# $NetBSD: Makefile,v 1.2 2015/09/14 22:26:14 yhardy Exp $

DISTNAME=	ags-3.5.0.26
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=adventuregamestudio/}
GITHUB_TAG=	v.${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.adventuregamestudio.co.uk/
COMMENT=	Adventure Game Studio runtime engine
LICENSE=	artistic-2.0

WRKSRC=		${WRKDIR}/ags-${GITHUB_TAG}
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} --directory=Engine

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/ags

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Engine/ags ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${DESTDIR}${PREFIX}/share/doc/ags/
	${INSTALL_DATA} ${WRKSRC}/OPTIONS.md ${DESTDIR}${PREFIX}/share/doc/ags/
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/ags/

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/allegro/buildlink3.mk"
# builds own copy of freetype
#.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
# TODO: switch to audio/dumb
# needs libaldmb.so
.include "../../wip/dumb/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
