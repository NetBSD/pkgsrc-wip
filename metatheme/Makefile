# $NetBSD: Makefile,v 1.7 2004/08/17 18:31:02 tvierling Exp $
#

DISTNAME=		metatheme-0.9.7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/metatheme/0.9/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Themes for GNOME 2

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
BUILD_USES_MSGFMT=	yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libmtm.la
LIBTOOL_LA_FILES+=	lib/metatheme/plugins/${PKGVERSION}/libbgplugin.la
LIBTOOL_LA_FILES+=	lib/metatheme/plugins/${PKGVERSION}/libgtkplugin1.la
LIBTOOL_LA_FILES+=	lib/metatheme/plugins/${PKGVERSION}/libgtkplugin2.la
LIBTOOL_LA_FILES+=	lib/metatheme/plugins/${PKGVERSION}/libnautilus.la
LIBTOOL_LA_FILES+=	lib/metatheme/plugins/${PKGVERSION}/libsawfish.la
GNU_CONFIGURE=		yes

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
