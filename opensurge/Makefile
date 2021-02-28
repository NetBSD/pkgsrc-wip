# $NetBSD$

DISTNAME=	opensurge-0.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=alemart/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opensurge2d.org/
COMMENT=	2D retro platformer inspired by Sonic games
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DGAME_BINDIR=${PREFIX}/bin
CMAKE_ARGS+=	-DGAME_DATADIR=${PREFIX}/share/${PKGBASE}
CMAKE_ARGS+=	-DDESKTOP_ICON_PATH=${PREFIX}/share/pixmaps
CMAKE_ARGS+=	-DDESKTOP_ENTRY_PATH=${PREFIX}/share/applications
CMAKE_ARGS+=	-DDESKTOP_METAINFO_PATH=${PREFIX}/share/metainfo

.include "../../devel/allegro5/buildlink3.mk"
.include "../../lang/surgescript/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
