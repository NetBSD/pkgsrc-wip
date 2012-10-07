# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:43 asau Exp $
#

DISTNAME=	py_hfk
PKGNAME=	${PYPKGPREFIX}-hfk-${VERSION}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.uic.edu/pub/t3m/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uic.edu/~t3m/
COMMENT=	Computes Heegaard Floer homology for links

VERSION=	1.0
USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
