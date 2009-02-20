# $NetBSD: Makefile,v 1.6 2009/02/20 21:51:24 guigui2 Exp $
#

DISTNAME=       giggle-0.4.91
CATEGORIES=     devel
MASTER_SITES=   ${MASTER_SITE_GNOME:=sources/giggle/0.4/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=     netbsd@guigui2.neT
HOMEPAGE=       http://live.gnome.org/giggle
COMMENT=        GTK2 graphical frontend to git SCM tool

DEPENDS+=       scmgit-base-[0-9]*:../../devel/scmgit-base

GNU_CONFIGURE=  yes
USE_LIBTOOL=    yes
USE_TOOLS+=     gmake intltool perl pkg-config
USE_DIRS+=      xdg-1.4

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
