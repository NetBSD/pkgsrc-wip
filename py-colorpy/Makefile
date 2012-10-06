# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:29 asau Exp $
#

DISTNAME=	colorpy-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics python
MASTER_SITES=	http://markkness.net/colorpy/dist/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://markkness.net/colorpy/ColorPy.html
COMMENT=	Handling physical descriptions of color and light spectra
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3


#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
