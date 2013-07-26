# $NetBSD: Makefile,v 1.1 2013/07/26 21:46:56 jihbed Exp $

DISTNAME=	symath-0.1.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/symath/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/bniemczyk/symbolic
COMMENT=	symbolic mathematics for python
LICENSE=	2-clause-bsd

FETCH_USING=    curl

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
