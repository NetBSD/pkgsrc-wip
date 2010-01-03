# $NetBSD: Makefile,v 1.1.1.1 2010/01/03 22:19:30 jihbed Exp $
#

DISTNAME=	gappa-0.12.3
CATEGORIES=	devel
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/24731/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://gappa.gforge.inria.fr/
COMMENT=	Formal tool for certifying numerical applications
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config bison flex
USE_LANGUAGES=	c c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
