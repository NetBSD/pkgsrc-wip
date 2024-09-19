# $NetBSD: Makefile,v 1.14 2013/09/09 14:05:30 thomasklausner Exp $

DISTNAME=	giggle-0.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/giggle/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	https://live.gnome.org/giggle
COMMENT=	GTK2 graphical frontend to git SCM tool
LICENSE=	gnu-gpl-v2

DEPENDS+=	git-base-[0-9]*:../../devel/git-base
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
