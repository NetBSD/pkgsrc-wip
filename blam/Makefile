# $NetBSD: Makefile,v 1.2 2009/06/22 14:10:14 jihbed Exp $
#

DISTNAME=	blam-1.8.6
CATEGORIES=	www
MASTER_SITES=	http://www.cmartin.tk/blam/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.cmartin.tk/blam.html
COMMENT=	Blam is a feed reader for GNOME written in C#

PKG_DESTDIR_SUPPORT=		user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=		pkg-config intltool
USE_LANGUAGES=		c
USE_DIRS+= 		xdg-1.4 gnome2-1.6

SUBST_CLASSES+=		schema
SUBST_STAGE.schema=	pre-configure
SUBST_MESSAGE.schema=	Fixing schema installation path.
SUBST_FILES.schema+=	data/Makefile.in
SUBST_SED.schema+=	-e "s,..sysconfdir./gconf/schemas,${PREFIX}/share/gconf/schemas/,"

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../wip/webkit-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
