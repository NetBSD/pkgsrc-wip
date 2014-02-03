# $NetBSD: Makefile,v 1.5 2014/02/03 11:08:48 othyro Exp $

DISTNAME=	redis-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-py-/1}
CATEGORIES=	databases
MASTER_SITES=	https://pypi.python.org/packages/source/r/redis/

DEPENDS+=	redis-[0-9]*:../../databases/redis

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/andymccurdy/redis-py/
COMMENT=	Redis Python client
LICENSE=	mit

EGG_NAME=	${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
