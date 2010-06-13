# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:03 thomasklausner Exp $
#

DISTNAME=	evolution-rss-0.1.4
PKGREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://gnome.eu.org/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gnome.eu.org/evo/index.php/Evolution_RSS_Reader_Plugin
COMMENT=	Evolution rss reader plugin
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool  gmake msgfmt
USE_LANGUAGES=	c c++

GCONF_SCHEMAS+=	src/evolution-rss.schemas

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgtkhtml+=		libgtkhtml>=2.6.0
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
