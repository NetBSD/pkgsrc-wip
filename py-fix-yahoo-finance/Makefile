# $NetBSD$

DISTNAME=	fix-yahoo-finance-0.0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fix-yahoo-finance/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/ranaroussi/fix-yahoo-finance
COMMENT=	Yahoo! Finance Fix for py-pandas_datareader
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-multitasking>=0.0.3:../../wip/py-multitasking
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.11.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests>=2.14.2:../../devel/py-requests

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/sample

.include "../../mk/bsd.pkg.mk"
