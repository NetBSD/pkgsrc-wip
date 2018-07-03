# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:45 thomasklausner Exp $

DISTNAME=	asciidata-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.stecf.org/software/PYTHONtools/astroasciidata/source/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.stecf.org/software/PYTHONtools/astroasciidata/
COMMENT=	Asciidata , to handle (read/modify/write) ASCII tables
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-fits>=2.3.1:../../graphics/py-fits

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-numarray

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
