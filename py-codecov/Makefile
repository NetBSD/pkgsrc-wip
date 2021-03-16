# $NetBSD$

DISTNAME=	codecov-2.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/codecov/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/codecov/codecov-python
COMMENT=	Python report uploader for Codecov
LICENSE=	apache-2.0

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} codecov codecov-${PYVERSSUFFIX}

DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.9:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
