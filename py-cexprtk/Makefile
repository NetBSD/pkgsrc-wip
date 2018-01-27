# $NetBSD$

DISTNAME=	cexprtk-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cexprtk/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/mjdr/cexprtk
COMMENT=	Cython wrapper the C++ Mathematical Expression Toolkit Library
LICENSE=	cpl-1.0

WRKSRC=		${WRKDIR}/cexprtk-0.2.0

USE_LANGUAGES=	c c++

BUILD_TARGET=	cexprtk.so

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
