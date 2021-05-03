# $NetBSD$

DISTNAME=	libgfbgraph-v_0_2_4
PKGNAME=	libgfbgraph-0.2.4
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.gnome.org/GNOME/libgfbgraph/-/archive/v_0_2_4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libgfbgraph/-/archive/v_0_2_4/
COMMENT=	GObject library for Facebook Graph API
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake autoconf automake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libgfbgraph.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../net/gnome-online-accounts/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/librest07/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
