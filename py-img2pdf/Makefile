# $NetBSD$

DISTNAME=	img2pdf-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/img2pdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/img2pdf/
COMMENT=	Lossless conversion of raster images to PDF
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config

REPLACE_PYTHON+=	src/img2pdf.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
