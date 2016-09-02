# $NetBSD: Makefile,v 1.4 2013/01/19 02:07:16 akihabara Exp $

DISTNAME=	slowaes-0.1a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slowaes/}

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	http://code.google.com/p/slowaes/
COMMENT=	Implementation of AES in pure Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # as of 0.1a1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
