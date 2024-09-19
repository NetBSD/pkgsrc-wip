# $NetBSD: Makefile,v 1.3 2015/09/06 14:31:49 slitvinov Exp $

DISTNAME=	gts-snapshot
SNAPDATE=	121130
PKGNAME=	gts-0.7.6.${SNAPDATE}
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

WRKSRC=	${WRKDIR}/gts-snapshot-${SNAPDATE}

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
