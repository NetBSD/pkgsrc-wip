# $NetBSD$

DISTNAME=	pymatgen-2020.9.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	https://files.pythonhosted.org/packages/90/e3/6ae04e52a58280dd28090e8c87f25584fe4d837b5e630d9b4909e1e41802/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pymatgen.org/
COMMENT=	Genomics is a robust materials analysis for structures and molecules
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-ipython>=7.18.1:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.4:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.0.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-uncertainties>=3.1.4:../../math/py-uncertainties
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.9.1:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-tabulate>=0.8.7:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-monty>=0.7.2:../../wip/py-monty
DEPENDS+=	${PYPKGPREFIX}-plotly>=4.8.1:../../wip/py-plotly
DEPENDS+=	${PYPKGPREFIX}-spglib>=1.16.0:../../wip/py-spglib

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
