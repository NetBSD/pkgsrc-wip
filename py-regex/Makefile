# $NetBSD$

DISTNAME=	regex-2015.10.01
PKGNAME=	${PYPKGPREFIX}-regex-20151001
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bitbucket.org/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

WRKSRC=	${WRKDIR}/regex-2015.10.01

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/Python2; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_regex.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
