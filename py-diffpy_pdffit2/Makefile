# $NetBSD: Makefile,v 1.3 2013/06/04 07:45:23 thomasklausner Exp $
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

.include "../../lang/python/egg.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
