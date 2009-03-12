# $NetBSD: Makefile,v 1.1.1.1 2009/03/12 00:24:34 jihbed Exp $
#

DISTNAME=	nautilus-open-terminal-0.9
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-open-terminal/0.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://manny.cluecoder.org/packages/nautilus-open-terminal/
COMMENT=	Nautilus extension which allows you to open a terminal

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config perl intltool gmake

GCONF_SCHEMAS+=	nautilus-open-terminal.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/eel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
