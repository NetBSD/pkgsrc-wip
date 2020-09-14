# $NetBSD$

DISTNAME=	efmlrs-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/ee/f0/ab1af72bb71db7fd769a42b0bf4ffc34ebf1d8a3d1baf80abd240bc290a5/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/BeeAnka/EFMlrs
COMMENT=	Extracts EFMs from result file of mplrs and decompresses EFMs
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
