# $NetBSD: Makefile,v 1.11 2010/04/26 21:08:35 guigui2 Exp $
#

DISTNAME=	giggle-0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/giggle/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://live.gnome.org/giggle
COMMENT=	GTK2 graphical frontend to git SCM tool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config intltool

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
