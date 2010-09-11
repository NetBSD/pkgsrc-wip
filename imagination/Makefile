# $NetBSD: Makefile,v 1.6 2010/09/11 12:35:18 jihbed Exp $
#

DISTNAME=	imagination-1.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://ovh.dl.sourceforge.net/sourceforge/imagination/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://imagination.sourceforge.net/
COMMENT=	Imagination a simple and lightweight DVD slideshow maker

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool perl gmake
USE_LANGUAGES=	c c++


.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
