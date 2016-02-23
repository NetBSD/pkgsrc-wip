# $NetBSD: Makefile,v 1.1 2015/07/03 17:48:55 jihbed Exp $

DISTNAME=	future-0.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/future/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://python-future.org/
COMMENT=	Clean single-source support for Python 3 and 2
LICENSE=	mit

USE_LANGUAGES=	# none

PLIST_VARS+=    pre30 post30

# for python < 3.0
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 30
PLIST.pre30=	yes
.else
PLIST.post30=	yes
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
