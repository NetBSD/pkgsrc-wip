# $NetBSD$

DISTNAME=	flipper-0.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/6a/50/14cb11ecb1f3d79aae8170108700d3cb8ba389cd4db1cdb3e03b0421b1d1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MarkCBell/flipper
COMMENT=	Manipulating curves and measured laminations on surfaces
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.3.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.0:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-realalg>=0.3.3:../../wip/py-realalg>

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.15.1
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
