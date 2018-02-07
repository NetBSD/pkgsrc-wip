# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:14 othyro Exp $

DISTNAME=	colorpy-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	http://markkness.net/colorpy/dist/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://markkness.net/colorpy/ColorPy.html
COMMENT=	Handling physical descriptions of color and light spectra
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
