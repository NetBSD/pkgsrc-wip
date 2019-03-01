# $NetBSD: Makefile,v 1.13 2015/06/06 18:48:10 krytarowski Exp $
#

DISTNAME=	plank-0.11.4
CATEGORIES=	wm gnome
MASTER_SITES=	http://launchpad.net/plank/1.0/${PKGVERSION_NOREV}/+download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://launchpad.net/plank/
COMMENT=	Simplest dock on the planet
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config gsed automake

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../devel/libgee/buildlink3.mk"
.include "../../wip/bamf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
