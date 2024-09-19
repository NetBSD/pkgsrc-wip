# $NetBSD: Makefile,v 1.9 2013/06/16 09:19:06 noud4 Exp $
#

DISTNAME=	tasks-0.20
CATEGORIES=	time editors
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tasks/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://pimlico-project.org/tasks.html
COMMENT=	Simple To Do list application for GNOME
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config gmake

CONFIGURE_ARGS+=	--disable-omoko
CONFIGURE_ARGS+=	--disable-hildon
CONFIGURE_ARGS+=	--without-owl

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.12.0
BUILDLINK_ABI_DEPENDS.gtk2+=	gtk2+>=2.8.17nb1

.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-unique
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
