# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:28 asau Exp $
#

DISTNAME=	pymc-2.1beta
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymc/}
EXTRACT_SUFX=	.zip#md5=265be6fe114f2d52359d59f2c8b912ff

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pymc
COMMENT=	Markov Chain Monte Carlo sampling toolkit
LICENSE=	afl

USE_LANGUAGES=	c fortran
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
