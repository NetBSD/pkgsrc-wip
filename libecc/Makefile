# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:44 othyro Exp $
#

DISTNAME=	libecc-0.14.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libecc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://libecc.sourceforge.net/
COMMENT=	C++ elliptic curve library
#LICENSE=	# TODO: (see mk/license.mk)

MAKE_JOBS_SAFE=	NO

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
