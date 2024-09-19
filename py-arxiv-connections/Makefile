# $NetBSD$

DISTNAME=	arxiv-connections-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/93/e1/78dd17c48dd6611711de4ddc6f4315ed7edece86f743bb7c22c41a4a0ea5/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.org/project/arxiv-connections/
COMMENT=	Python package used to visualize academics and find related people
#LICENSE=	# TODO: (see mk/license.mk)

#DEPENDS+=	${PYPKGPREFIX}-arxiv>=0.5.3,<0.6.0:../../category/py-arxiv
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	# TODO: nb_black>=1.0.7,<2.0.0
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.4:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.1.0:../../math/py-pandas
#DEPENDS+=	${PYPKGPREFIX}-plotly>=4.9.0,<5.0.0:../../wip/py-plotly
DEPENDS+=	${PYPKGPREFIX}-wheel>=0.34.2:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
