# $NetBSD: Makefile,v 1.1 2015/08/30 22:42:37 slitvinov Exp $

DISTNAME=	gts-snapshot
SNAPDATE=	121130
PKGNAME=	gts.${SNAPDATE}
CATEGORIES=	graphics
MASTER_SITES=	http://gts.sf.net/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://gts.sf.net/
COMMENT=	GTS stands for the GNU Triangulated Surface Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	gts.pc.in

INSTALLATION_DIRS+=	bin

WRKSRC=${WRKDIR}/gts-snapshot-121130

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
