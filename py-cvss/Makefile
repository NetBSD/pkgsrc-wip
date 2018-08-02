# $NetBSD$

DISTNAME=	cvss-1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=skontar/}
GITHUB_PROJECT=	cvss
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/skontar/cvss
COMMENT=	CVSS2/3 library with interactive calculator
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_cvss2.py
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_cvss3.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cvss_calculator ${DESTDIR}${PREFIX}/bin/cvss_calculator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
