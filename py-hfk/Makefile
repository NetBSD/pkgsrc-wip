# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 16:16:43 jihbed Exp $
#

DISTNAME=	py_hfk
PKGNAME=	${PYPKGPREFIX}-hfk-${VERSION}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.uic.edu/pub/t3m/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uic.edu/~t3m/
COMMENT=	Computes Heegaard Floer homology for links

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	1.0
USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
