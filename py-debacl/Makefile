# $NetBSD: Makefile,v 1.1 2013/09/09 00:09:38 jihbed Exp $

DISTNAME=	debacl-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/debacl/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/CoAxLab/DeBaCl
COMMENT=	Density-Based Clustering
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.11.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
