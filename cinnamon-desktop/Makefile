# $NetBSD: Makefile,v 1.2 2015/02/19 18:01:20 jihbed Exp $

DISTNAME=	cinnamon-desktop-3.8.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cinnamon-desktop
GITHUB_TAG=	${PKGVERSION_NOREV}


MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-desktop
COMMENT=	Additional UI API for cinnamon
LICENSE=	gnu-gpl-v2

#USE_LIBTOOL=	yes
#GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config automake autoreconf intltool msgfmt

REPLACE_PYTHON=	install-scripts/meson_install_schemas.py \
		files/usr/bin/cinnamon-desktop-migrate-mediakeys

PKGCONFIG_OVERRIDE+=	libcinnamon-desktop/cinnamon-desktop.pc.in

BUILD_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libcvc:${WRKSRC}/output/libcinnamon-desktop

pre-install:
	${CHMOD} +x ${WRKSRC}/install-scripts/meson_install_schemas.py

.include "../../devel/py-meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/application.mk"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
