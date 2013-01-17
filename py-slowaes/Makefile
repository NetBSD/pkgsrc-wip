# $NetBSD: Makefile,v 1.3 2013/01/17 08:52:58 akihabara Exp $

DISTNAME=	slowaes-0.1a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/s/slowaes/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	http://code.google.com/p/slowaes/
COMMENT=	Implementation of AES in pure Python
LICENSE=	apache-2.0

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
