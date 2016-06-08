# $NetBSD: Makefile,v 1.2 2014/05/02 23:07:56 jihbed Exp $

DISTNAME=	linop-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/linop/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ghisvail/linop
COMMENT=	Pythonic abstraction for linear mathematical operators
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
