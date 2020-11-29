# $NetBSD$

DISTNAME=	gnome-tweaks-3.34.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-tweaks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Tweaks
COMMENT=	Graphical interface for advanced GNOME 3 settings
#LICENSE=	# TODO: (see mk/license.mk)

USE_PKGLOCALEDIR=	yes
PY_PATCHPLIST=		yes

.include "../../devel/meson/build.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
