# $NetBSD: Makefile,v 1.3 2013/12/01 20:24:22 jihbed Exp $

DISTNAME=	ProDy-1.4.10
PKGNAME=	${PYPKGPREFIX}-prody-1.4.10
CATEGORIES=	biology
MASTER_SITES=	https://pypi.python.org/packages/source/P/ProDy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.csb.pitt.edu/ProDy
COMMENT=	Python Package for Protein Dynamics Analysis
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/ProDy-1.4.10

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
