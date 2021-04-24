# $NetBSD: Makefile,v 1.3 2013/06/04 07:45:23 thomasklausner Exp $

DISTNAME=	py_hfk
PKGNAME=	${PYPKGPREFIX}-hfk-${VERSION}
CATEGORIES=	math
#MASTER_SITES=	ftp://ftp.math.uic.edu/pub/t3m/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uic.edu/~t3m/
COMMENT=	Computes Heegaard Floer homology for links

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

VERSION=	1.0
USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
