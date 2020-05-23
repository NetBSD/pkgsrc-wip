# $NetBSD$

GITHUB_PROJECT=	jsonrpc-glib
GITHUB_TAG=	3.34.0
DISTNAME=	3.34.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/GNOME/jsonrpc-glib/
COMMENT=	JSON-RPC library for GLib
LICENSE=	gnu-lgpl-v2

WRKSRC=	${WRKDIR}/jsonrpc-glib-3.34.0

USE_TOOLS+=	pkg-config

.include "../../lang/vala/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
