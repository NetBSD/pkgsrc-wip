# $NetBSD: Makefile,v 1.2 2015/01/31 19:33:16 jihbed Exp $

DISTNAME=	hope-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hope/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hope.phys.ethz.ch/
COMMENT=	Python Just-In-Time compiler for astrophysical computations
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=      ${PYPKGPREFIX}-sympy>=0.7.4.1:../../math/py-sympy
.include "../../mk/bsd.pkg.mk"
