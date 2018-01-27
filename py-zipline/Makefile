# $NetBSD: Makefile,v 1.1 2012/11/09 18:14:45 jihbed Exp $
#

DISTNAME=	zipline-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zipline/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/quantopian/zipline
COMMENT=	Backtester for financial algorithms
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-alembic>=0.7.7:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-bcolz>=0.12.1:../../devel/py-bcolz
DEPENDS+=	${PYPKGPREFIX}-click>=4.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-contextlib2>=0.4.0:../../devel/py-contextlib2
DEPENDS+=	${PYPKGPREFIX}-cyordereddict>=0.2.2:../../devel/py-cyordereddict
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-empyrical>=0.2.2:../../finance/py-empyrical
DEPENDS+=	${PYPKGPREFIX}-intervaltree>=2.1.0:../../devel/py-intervaltree
DEPENDS+=	${PYPKGPREFIX}-logbook>=0.12.5:../../devel/py-logbook
DEPENDS+=	${PYPKGPREFIX}-lru-dict>=1.1.4:../../devel/py-lru-dict
DEPENDS+=	${PYPKGPREFIX}-mako>=1.0.1:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-multipledispatch>=0.4.8:../../devel/py-multipledispatch
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.9.1:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-numexpr>=2.6.1:../../math/py-numexpr
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-pandas-datareader>=0.2.1:../../math/py-pandas-datareader
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.4.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-pytables>=3.3.0:../../math/py-pytables
DEPENDS+=	${PYPKGPREFIX}-pytz>=2016.4:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-file>=1.4.1:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.4.4:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0.8:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-statsmodels>=0.6.1:../../math/py-statsmodels
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.2:../../wip/py-toolz

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.22.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.11.1
.include "../../math/py-numpy/buildlink3.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/zipline \
		${DESTDIR}${PREFIX}/bin/zipline${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
