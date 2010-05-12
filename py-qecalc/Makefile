# $NetBSD: Makefile,v 1.1.1.1 2010/05/12 16:09:47 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
