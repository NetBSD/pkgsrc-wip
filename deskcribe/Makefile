# $NetBSD: Makefile,v 1.6 2012/09/28 21:24:35 asau Exp $
#

DISTNAME=	deskscribe-0.4.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/deskscribe/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://launchpad.net/deskscribe
COMMENT=	DeskScribe is a usability testing suite
LICENSE=	gnu-gpl-v2 gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config gmake

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
