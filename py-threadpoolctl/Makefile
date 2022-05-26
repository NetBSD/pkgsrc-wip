# $NetBSD$

DISTNAME=	threadpoolctl-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/threadpoolctl/}

MAINTAINER=	matthewd@fastmail.us
COMMENT=	Python helpers to limit the number of threads of datascience tools
LICENSE=	modified-bsd

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
