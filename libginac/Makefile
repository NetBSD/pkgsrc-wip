# $NetBSD: Makefile,v 1.2 2011/01/17 22:33:46 jihbed Exp $
#

DISTNAME=	ginac-1.5.8
PKGNAME=	lib${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ginac.de/
COMMENT=	The GiNaC symbolic framework
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_GNU_READLINE=	yes
INFO_FILES=		yes
USE_TOOLS+=	bison gmake pkg-config makeinfo
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	ginac.pc.in

BUILDLINK_API_DEPENDS.readline+=	readline>=2.2
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.cln+=		cln>=1.1.6
.include "../../math/cln/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
