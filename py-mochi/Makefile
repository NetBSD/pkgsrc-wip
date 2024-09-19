# $NetBSD: Makefile,v 1.1 2015/01/18 23:00:27 jihbed Exp $

DISTNAME=	mochi-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mochi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/i2y/mochi
COMMENT=	Dynamically typed functional programming language
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.1:../../devel/py-greenlet
#DEPENDS+=	${PYPKGPREFIX}-rply>=0.16.1:../../devel/py-rply
DEPENDS+=	${PYPKGPREFIX}-eventlet>=0.16.1:../../wip/py-eventlet
DEPENDS+=	${PYPKGPREFIX}-pyrsistent>=0.7.1:../../devel/py-pyrsistent

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
