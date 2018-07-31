# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	cinnamon-session-3.8.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cinnamon-session
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-session
COMMENT=	Cinnamon session
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_TOOLS+=	gmake pkg-config intltool msgfmt

BUILD_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

LDFLAGS.SunOS+=	-lsocket

.include "../../wip/xapps/buildlink3.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
