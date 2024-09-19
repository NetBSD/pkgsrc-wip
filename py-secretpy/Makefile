# $NetBSD: Makefile,v 1.8 2021/03/04 10:20:48 leot Exp $

DISTNAME=	secretpy-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/secretpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tigertv/secretpy
COMMENT=	Classical cipher algorithms Python package
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
