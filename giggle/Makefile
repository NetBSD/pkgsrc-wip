# $NetBSD: Makefile,v 1.5 2008/12/04 22:21:02 thomasklausner Exp $
#

DISTNAME=		giggle-0.4
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://ftp.imendio.com/pub/imendio/giggle/src/

MAINTAINER=		netbsd@guigui2.net
HOMEPAGE=		http://developer.imendio.com/projects/giggle/
COMMENT=		GTK2 graphical frontend to git SCM tool

DEPENDS+=		scmgit-base-[0-9]*:../../devel/scmgit-base

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool perl pkg-config
USE_DIRS+=		xdg-1.4

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
