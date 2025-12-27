# $NetBSD$

DISTNAME=	psleak-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psleak/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psleak
COMMENT=	Detect memory and resource leaks in Python C extensions
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-instafail-[0-9]*:../../devel/py-test-instafail

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${MAKE} build test

.include "../../lang/python/wheel.mk"
# for test
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
