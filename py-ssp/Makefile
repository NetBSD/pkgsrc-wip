# $NetBSD: Makefile,v 1.3 2014/06/01 12:49:46 thomasklausner Exp $

DISTNAME=	pyssp-0.1.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyssp/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/aihara/pyssp/
COMMENT=	Python speech signal processing library for education
LICENSE=	cc-by-sa-v3.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
