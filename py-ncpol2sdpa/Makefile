# $NetBSD: Makefile,v 1.1 2014/10/18 19:40:50 jihbed Exp $

DISTNAME=	ncpol2sdpa-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/n/ncpol2sdpa/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://peterwittek.github.io/ncpol2sdpa/
COMMENT=	Converter from noncommutative variables to sparse SDPA
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.4.1:../../math/py-sympy
.include "../../mk/bsd.pkg.mk"
