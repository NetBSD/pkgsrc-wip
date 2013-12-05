# $NetBSD: Makefile,v 1.1 2013/12/05 11:00:42 jihbed Exp $

DISTNAME=	linop-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/l/linop/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ghisvail/linop
COMMENT=	Pythonic abstraction for linear mathematical operators
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
