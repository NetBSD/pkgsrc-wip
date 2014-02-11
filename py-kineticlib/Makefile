# $NetBSD: Makefile,v 1.2 2014/02/11 23:04:35 jihbed Exp $

DISTNAME=	kineticlib-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/k/kineticlib/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Kunstmord/kineticlib
COMMENT=	Library for kinetic theory calculations in the multi-temperature
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
