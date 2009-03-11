# $NetBSD: Makefile,v 1.1.1.1 2009/03/11 13:14:49 jihbed Exp $
#

DISTNAME=	deskscribe-0.4.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/deskscribe/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpad.net/deskscribe
COMMENT=	DeskScribe is a usability testing suite

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.4
GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config gmake

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
