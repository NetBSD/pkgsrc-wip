# $NetBSD: Makefile,v 1.9 2012/09/24 17:14:25 asau Exp $
#

DISTNAME=	bakery-2.6.3
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/bakery/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bakery.sourceforge.net/
COMMENT=	C++ Framework for creating GNOME applications using gtkmm
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=		--disable-maemo

PKGCONFIG_OVERRIDE+=	bakery-2.6.pc.in

BUILDLINK_API_DEPENDS.gtkmm+=		gtkmm>=2.14.3

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
