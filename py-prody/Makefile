# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	ProDy-1.4.10
PKGNAME=	${PYPKGPREFIX}-prody-1.4.10
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=P/ProDy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.csb.pitt.edu/ProDy
COMMENT=	Python Package for Protein Dynamics Analysis
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/ProDy-1.4.10

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
