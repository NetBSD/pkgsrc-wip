# $NetBSD$

DISTNAME=	VESPA-0.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/56/91/170b0343dd695104b070d33cf4c808c77f7dca1f2399a8c0af18a0e0f0b1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/timothydmorton/VESPA
COMMENT=	Calculate astrophysical false positive probabilities
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas

USE_TOOLS+=	perl

REPLACE_PERL=	scripts/get_trilegal${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/scripts/get_trilegal ${WRKSRC}/scripts/get_trilegal${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/koifpp ${WRKSRC}/scripts/koifpp${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/batch_koifpp_condor ${WRKSRC}/scripts/batch_koifpp_condor${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/calcfpp ${WRKSRC}/scripts/calcfpp${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/koifpp-config ${WRKSRC}/scripts/koifpp-config${PYVERSSUFFIX}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
