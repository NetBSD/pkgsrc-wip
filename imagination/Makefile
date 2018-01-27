# $NetBSD: Makefile,v 1.9 2014/08/11 23:10:13 thomasklausner Exp $

DISTNAME=	imagination-1.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imagination/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://imagination.sourceforge.net/
COMMENT=	Imagination a simple and lightweight DVD slideshow maker

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool perl gmake
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	have_ffmpeg=${BUILDLINK_PREFIX.ffmpeg1}/bin/ffmpeg1

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
