# $NetBSD: Makefile,v 1.5 2009/08/07 17:51:44 jihbed Exp $
#

DISTNAME=	nautilus-open-terminal-0.16
CATEGORIES=	wip
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/nautilus-open-terminal/0.16/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/nautilus-open-terminal/
COMMENT=	Nautilus extension which allows you to open a terminal
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=  yes
CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool msgfmt
USE_LANGUAGES=	c c++

GCONF_SCHEMAS+=	nautilus-open-terminal.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
