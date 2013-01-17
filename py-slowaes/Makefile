# $NetBSD: Makefile,v 1.2 2013/01/17 08:28:34 akihabara Exp $

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
