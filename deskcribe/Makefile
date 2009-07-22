# $NetBSD: Makefile,v 1.2 2009/07/22 09:53:11 thomasklausner Exp $
#

DISTNAME=	deskscribe-0.4.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/deskscribe/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpad.net/deskscribe
COMMENT=	DeskScribe is a usability testing suite

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config gmake

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
