# $NetBSD: Makefile,v 1.3 2015/01/31 22:33:20 jihbed Exp $

DISTNAME=	symath-0.1.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/symath/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bniemczyk/symbolic
COMMENT=	symbolic mathematics for python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing

WRKSRC=		${WRKDIR}/symath-0.1.22

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
