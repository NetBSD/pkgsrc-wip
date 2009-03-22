# $NetBSD: Makefile,v 1.1.1.1 2009/03/22 16:02:38 jihbed Exp $
#

DISTNAME=	gxmessage-2.6.2
CATEGORIES=	x11
MASTER_SITES=	http://homepages.ihug.co.nz/~trmusson/stuff/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://homepages.ihug.co.nz/~trmusson/programs.html#gxmessage/
COMMENT=	Gxmessage a GTK2+ based xmessage clone

PKG_DESTDIR_SUPPORT=		user-destdir
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool pkg-config
USE_DIRS+= 		xdg-1.4


.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
