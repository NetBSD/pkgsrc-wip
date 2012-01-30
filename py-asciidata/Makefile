# $NetBSD: Makefile,v 1.2 2012/01/30 07:19:57 noud4 Exp $
#

DISTNAME=	asciidata-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.stecf.org/software/PYTHONtools/astroasciidata/source/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.stecf.org/software/PYTHONtools/astroasciidata/
COMMENT=	Asciidata , to handle (read/modify/write) ASCII tables
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.3.1:../../graphics/py-pyfits

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes


.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
