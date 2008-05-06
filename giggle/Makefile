# $NetBSD: Makefile,v 1.1.1.1 2008/05/06 20:54:29 guigui2 Exp $
#

DISTNAME=		giggle-0.4
CATEGORIES=		devel
MASTER_SITES=		http://ftp.imendio.com/pub/imendio/giggle/src/

MAINTAINER=		netbsd@guigui2.net
HOMEPAGE=		http://ftp.imendio.com/pub/imendio/giggle/src/
COMMENT=		GTK2 graphical frontend to git source code management

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config perl gmake
USE_DIRS+=		xdg-1.4

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
