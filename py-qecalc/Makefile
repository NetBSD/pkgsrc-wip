# $NetBSD: Makefile,v 1.5 2014/12/31 13:58:40 thomasklausner Exp $
#

DISTNAME=	qecalc-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://danse.cacr.caltech.edu/packages/dev_danse_us/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://docs.danse.us/AbInitio/espresso/qecalc/index.html
COMMENT=	Wrapper for Quantum Espresso
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-diffpy-structure-[0-9]*:../../wip/py-diffpy-structure

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-yapps2 via py-pycifrw via py-diffpy-structure

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
