# $NetBSD: Makefile,v 1.1.1.1 2010/03/19 19:40:00 jihbed Exp $
#

DISTNAME=	gwget-1.0.4
CATEGORIES=	gnome net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gwget/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://projects.gnome.org/gwget/
COMMENT=	GNOME wget front-end
LICENSE=	gnu-gpl-v2

DEPENDS+=	wget>=1.12:../../net/wget

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake

GCONF_SCHEMAS+=	data/gwget.schemas

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
