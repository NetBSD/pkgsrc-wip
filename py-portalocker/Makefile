# $NetBSD$

DISTNAME=	portalocker-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/portalocker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/portalocker/
COMMENT=	Python library for file locking
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-redis-[0-9]*:../../databases/py-redis

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
