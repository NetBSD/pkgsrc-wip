# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	pdef-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdef/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pdef/pdef-python
COMMENT=	Protocol definition language
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
