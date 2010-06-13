# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:07 thomasklausner Exp $
#

DISTNAME=	gts-0.7.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://garr.dl.sourceforge.net/project/gts/gts/0.7.6/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://gts.sourceforge.net/
COMMENT=	GTS stands for the GNU Triangulated Surface Library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	gts.pc.in

INSTALLATION_DIRS+=	bin

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
