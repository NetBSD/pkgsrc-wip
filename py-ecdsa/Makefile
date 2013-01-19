# $NetBSD: Makefile,v 1.1 2013/01/19 01:57:17 akihabara Exp $

DISTNAME=	ecdsa-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/e/ecdsa/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	https://github.com/warner/python-ecdsa
COMMENT=	ECDSA cryptographic signature library (pure python)
LICENSE=	mit

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
