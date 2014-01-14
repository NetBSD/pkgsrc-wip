# $NetBSD: Makefile,v 1.1 2014/01/14 16:50:42 jihbed Exp $

DISTNAME=	pdef-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/p/pdef/
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pdef/pdef-python
COMMENT=	Protocol definition language
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
