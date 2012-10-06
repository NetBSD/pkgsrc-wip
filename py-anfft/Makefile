# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:31 asau Exp $
#

DISTNAME=	anfft-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://anfft.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/anfft/
COMMENT=	FFT package for Python, based on FFTW
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/anfft; ${SETENV} ${TEST_ENV} ${PYTHONBIN} _test.py

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
