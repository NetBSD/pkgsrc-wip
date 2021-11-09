# $NetBSD: Makefile,v 1.45 2020/12/18 09:03:43 adam Exp $

DISTNAME=	pip-audit-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip-audit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pip-audit/
COMMENT=	Scan Python environments for known vulnerabilities
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.12.6:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.12.2:../../devel/py-lockfile
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.0.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip-api>=0.0.23:../../wip/py-pip-api
DEPENDS+=	${PYPKGPREFIX}-progress>=1.6:../../wip/py-progress
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=0.8.0:../../wip/py-resolvelib
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
        ${MV} pip-audit pip-audit-${PYVERSSUFFIX} || ${TRUE}

# needs package installed
# 2 test failures as of 0.0.4:
# https://github.com/trailofbits/pip-audit/issues/115
do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
