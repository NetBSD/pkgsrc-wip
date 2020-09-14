# $NetBSD$

DISTNAME=	pytrends-4.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net misc python
MASTER_SITES=	https://files.pythonhosted.org/packages/72/13/9e2f2eb64dfd017126fe9522d9dc6023df50b479dc482dad3dd54672ee4b/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreyco676/pytrends
COMMENT=	Pseudo API for Google Trends
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
