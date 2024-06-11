# $NetBSD$

DISTNAME=	xdg-desktop-portal-1.18.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=flatpak/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flatpak/xdg-desktop-portal/releases/download/1.18.4/ # TODO: check
COMMENT=	Desktop integration portal (from Flatpak)
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
