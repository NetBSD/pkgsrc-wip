# $NetBSD: Makefile,v 1.2 2015/02/19 18:01:20 jihbed Exp $

DISTNAME=	3.0.2
PKGNAME=	cinnamon-desktop-3.0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/cinnamon-desktop/archive/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://github.com/linuxmint/cinnamon-desktop
COMMENT=	Additional UI API for cinnamon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config automake autoreconf intltool msgfmt

BUILD_DEPENDS+=		gettext-m4>=0.14.6:../../devel/gettext-m4
BUILD_DEPENDS+=		gnome-common-[0-9]*:../../devel/gnome-common

PKGCONFIG_OVERRIDE+=	libcinnamon-desktop/cinnamon-desktop.pc.in

pre-configure:
	cd ${WRKSRC} && ${SH}  ./autogen.sh

BUILD_DEPENDS+=	gnome-common-[0-9]*:../../devel/gnome-common

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
