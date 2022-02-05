# $NetBSD$

DISTNAME=	apprise-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apprise/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/caronc/apprise
COMMENT=	Notify muliple services with one interface
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

# as of 0.9.6
# 1 skipped, 2 warnings, 1 error
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
