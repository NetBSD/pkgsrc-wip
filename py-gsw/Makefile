# $NetBSD: Makefile,v 1.1 2015/08/05 21:32:58 jihbed Exp $

DISTNAME=	gsw-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gsw/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/seawater/
COMMENT=	Gibbs SeaWater Oceanographic Package of TEOS-10
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
