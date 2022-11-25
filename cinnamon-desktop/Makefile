# $NetBSD$

GITHUB_PROJECT=	cinnamon-desktop
GITHUB_TAG=	refs/tags/master.mint21
DISTNAME=	master.mint21
VERSION=		4.0.0
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-desktop/
COMMENT=	Additional UI API for cinnamon
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/cinnamon-desktop-master.mint21

USE_TOOLS+=	pkg-config intltool msgfmt
USE_PKGLOCALEDIR=	yes

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libcvc:${WRKSRC}/output/libcinnamon-desktop

REPLACE_PYTHON=	install-scripts/meson_install_schemas.py

.include "../../audio/pulseaudio/buildlink3.mk""
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
