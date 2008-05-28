# $NetBSD: Makefile,v 1.4 2008/05/28 11:16:26 guigui2 Exp $
#

DISTNAME=		giggle-0.4
CATEGORIES=		devel
MASTER_SITES=		http://ftp.imendio.com/pub/imendio/giggle/src/

MAINTAINER=		netbsd@guigui2.net
HOMEPAGE=		http://developer.imendio.com/projects/giggle/
COMMENT=		GTK2 graphical frontend to git SCM tool

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config perl gmake intltool
USE_DIRS+=		xdg-1.4

DEPENDS+=		scmgit-base-[0-9]*:../../devel/scmgit-base

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
