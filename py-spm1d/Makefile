# $NetBSD$

DISTNAME=	spm1d-0.3.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spm1d/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/0todd0000/spm1d
COMMENT=	One-Dimensional Statistical Parametric Mapping
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
