# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:23 thomasklausner Exp $

DISTNAME=	python-coveralls-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-coveralls/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://github.com/z4r/python-coveralls
COMMENT=	Python interface to coveralls.io API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-coverage>=3.7.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

WRKSRC=		${WRKDIR}/python-coveralls-2.4.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
