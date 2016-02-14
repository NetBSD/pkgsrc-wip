# $NetBSD$

DISTNAME=	rpyc-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpyc/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	http://rpyc.readthedocs.org/
COMMENT=	Remote Python Call (RPyC), a transparent and symmetric RPC library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-plumbum>=1.6.1:../../wip/py-plumbum

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
