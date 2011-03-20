# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 23:26:42 jihbed Exp $
#

DISTNAME=	pymc-2.1beta
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pymc/
EXTRACT_SUFX=	.zip#md5=265be6fe114f2d52359d59f2c8b912ff

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pymc
COMMENT=	Markov Chain Monte Carlo sampling toolkit
LICENSE=	afl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c fortran
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
