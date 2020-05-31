# $NetBSD$

DISTNAME=	template-glib-3.34.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/template-glib/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://gitlab.gnome.org/GNOME/template-glib
COMMENT=	Glib template expansion library
LICENSE=	gnu-lgpl-v2

USE_PKGLOCALEDIR=	yes

USE_TOOLS+=	pkg-config

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
