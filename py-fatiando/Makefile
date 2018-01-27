# $NetBSD: Makefile,v 1.1 2012/11/09 18:11:16 jihbed Exp $
#

DISTNAME=	fatiando-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fatiando/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.fatiando.org/
COMMENT=	Geophysical direct and inverse modeling
LICENSE=	gnu-lgpl-v3

WRKSRC=	${WRKDIR}/fatiando-0.0.1

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
