# $NetBSD: Makefile,v 1.4 2014/12/31 13:58:27 thomasklausner Exp $
#

DISTNAME=	diffpy.pdffit2-${VERSION}
EGG_NAME=	diffpy.pdffit2-1.0_r3067_20090410
PKGNAME=	${PYPKGPREFIX}-diffpy-pdffit2-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://www.diffpy.org/packages/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.diffpy.org/
COMMENT=	PDFfit2 - real space structure refinement program
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-diffpy-structure-[0-9]*:../../wip/py-diffpy-structure
DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline

VERSION=	1.0-r3067-20090410
USE_LANGUAGES=	c c++
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-yapps2 via py-pycifrw via py-diffpy-structure

.include "../../lang/python/egg.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
