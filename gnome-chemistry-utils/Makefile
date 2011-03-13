# $NetBSD: Makefile,v 1.3 2011/03/13 03:52:27 ryo-on Exp $
#

DISTNAME=	gnome-chemistry-utils-0.13.2
CATEGORIES=	biology
MASTER_SITES=	http://download.savannah.gnu.org/releases/gchemutils/0.13/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gchemutils.nongnu.org/
COMMENT=	GChemPaint, a 2D chemical editor and other programs
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt xgettext msgmerge perl
USE_LANGUAGES=	c c++

GCONF_SCHEMAS+=	gchemutils.schemas
GCONF_SCHEMAS+=	plugins/paint/arrows/gchempaint-arrows.schemas
GCONF_SCHEMAS+=	programs/crystal/gcrystal.schemas
GCONF_SCHEMAS+=	programs/paint/gchempaint.schemas

BUILDLINK_TRANSFORM+=rm:-DGTK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=rm:-ldl

.include "../../devel/GConf/schemas.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../misc/goffice0.8/buildlink3.mk"
.include "../../wip/chemical-mime-data/buildlink3.mk"
.include "../../wip/bodr/buildlink3.mk"
.include "../../wip/openbabel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
