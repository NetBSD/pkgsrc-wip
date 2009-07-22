# $NetBSD: Makefile,v 1.4 2009/07/22 09:53:12 thomasklausner Exp $
#

DISTNAME=	glista-0.4
CATEGORIES=	time gnome
MASTER_SITES=	http://glista.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://prematureoptimization.org/glista/
COMMENT=	Simple task list management utility

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-linkify-urls

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
CONFIGURE_ARGS+=		--with-gtkspell
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.2
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
