# $NetBSD$

DISTNAME=	graphene-1.10.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebassi/graphene/releases/download/1.10.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/ebassi/graphene
COMMENT=	Thin layer of graphic data types
LICENSE=	mit

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dgobject_types=true
MESON_ARGS+=	-Dintrospection=true

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
