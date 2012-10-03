# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:38 asau Exp $
#

DISTNAME=	libecc-0.14.0
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/libecc/libecc/0.14.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://garr.dl.sourceforge.net/project/libecc/libecc/0.14.0/
COMMENT=	C++ elliptic curve library
#LICENSE=	# TODO: (see mk/license.mk)

MAKE_JOBS_SAFE=NO

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
