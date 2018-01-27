# $NetBSD: Makefile,v 1.1 2015/08/05 20:56:48 jihbed Exp $

DISTNAME=	mave-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mave/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/m/mave/
COMMENT=	Library for Measurement and Verification
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil

WRKSRC=		${WRKDIR}/mave-0.0.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
