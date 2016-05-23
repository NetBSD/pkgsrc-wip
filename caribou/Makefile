# $NetBSD: Makefile,v 1.13 2013/06/19 12:15:39 noud4 Exp $
#

DISTNAME=	caribou-0.4.20
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/caribou/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Caribou
COMMENT=	Simplified in-place on-screen keyboard
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config intltool gmake

PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
