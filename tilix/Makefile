# $NetBSD$

GITHUB_PROJECT=	tilix
GITHUB_TAG=	1.9.3
DISTNAME=	1.9.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnunn1/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/gnunn1/tilix/
COMMENT=	Tiling terminal emulator
LICENSE=	mpl-2.0

WRKSRC=			${WRKDIR}/tilix-1.9.3
USE_PKGLOCALEDIR=	yes

BUILD_DEPENDS+=	dub-*:../../wip/dub
BUILD_DEPENDS+= po4a-*:../../textproc/po4a

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../wip/ldc/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/gtk-d/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
