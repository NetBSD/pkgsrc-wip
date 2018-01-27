# $NetBSD: Makefile,v 1.1 2015/08/01 22:33:59 jihbed Exp $

DISTNAME=	pycalphad-0.1.1.post1
 PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycalphad/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/richardotis/pycalphad
COMMENT=	Thermodynamic models, calculating phase diagrams
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.16.2:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.4.1:../../math/py-sympy

WRKSRC=		${WRKDIR}/pycalphad-0.1.1.post1

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
