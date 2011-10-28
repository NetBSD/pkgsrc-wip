# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 17:37:04 jihbed Exp $
#

DISTNAME=	libecc-0.14.0
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/libecc/libecc/0.14.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://garr.dl.sourceforge.net/project/libecc/libecc/0.14.0/
COMMENT=	C++ elliptic curve library
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=NO

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
