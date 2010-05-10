# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 21:45:09 jihbed Exp $
#

DISTNAME=	ginac-1.5.5
PKGNAME=	lib${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ginac.de/
COMMENT=	The GiNaC symbolic framework
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_GNU_READLINE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	ginac.pc.in

BUILDLINK_API_DEPENDS.readline+=	readline>=2.2
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.cln+=		cln>=1.1.6
.include "../../math/cln/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
