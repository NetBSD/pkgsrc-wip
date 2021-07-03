# $NetBSD: Makefile,v 1.1 2021/06/23 21:07:29 wiz Exp $

DISTNAME=	spake2-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spake2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-spake2
COMMENT=	Pure-Python SPAKE2
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hkdf-[0-9]*:../../security/py-hkdf

PYTHON_VERSIONS_INCOMPATIBLE=	27 # devel/py-test is incompatible with 2.7 since 5.0.0
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
