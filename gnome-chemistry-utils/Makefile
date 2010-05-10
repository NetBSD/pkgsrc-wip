# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 21:41:24 jihbed Exp $
#

DISTNAME=	gnome-chemistry-utils-0.11.4
CATEGORIES=	biology
MASTER_SITES=	http://ftp.cc.uoc.gr/mirrors/nongnu.org/gchemutils/0.11/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://ftp.cc.uoc.gr/mirrors/nongnu.org/gchemutils/0.11/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkgc-config perl msgfmt intltool
USE_LANGUAGES=	c c++

GCONF_SCHEMAS+=	gchemutils.schemas
GCONF_SCHEMAS+=	plugins/paint/arrows/gchempaint-arrows.schemas
GCONF_SCHEMAS+=	programs/crystal/gcrystal.schemas
GCONF_SCHEMAS+=	programs/paint/gchempaint.schemas

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.0.0nb2
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.16.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
