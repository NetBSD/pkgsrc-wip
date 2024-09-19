# $NetBSD$

DISTNAME=	redis-py-cluster-1.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis-py-cluster/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/grokzen/redis-py-cluster/
COMMENT=	Cluster library for redis 3.0.0 built on top of redis-py
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-redis-[0-9]*:../../databases/py-redis

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
