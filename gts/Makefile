# $NetBSD: Makefile,v 1.8 2014/09/08 21:24:08 thomasklausner Exp $
#

DISTNAME=	gts-0.7.6
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gts/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://gts.sourceforge.net/
COMMENT=	GTS stands for the GNU Triangulated Surface Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

CPPFLAGS+=	-I${BUILDLINK_PREFIX.netpbm}/${BUILDLINK_INCDIRS.netpbm}/netpbm
PKGCONFIG_OVERRIDE+=	gts.pc.in

INSTALLATION_DIRS+=	bin

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
