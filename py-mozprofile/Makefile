# $NetBSD$

DISTNAME=	mozprofile-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/0b/39/39c8237a511a26effc53020b801e452a04cf52c2c9d9b71dcc21262903ef/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://firefox-source-docs.mozilla.org/mozbase/mozprofile.html
COMMENT=	Library to create and modify Mozilla application profiles
LICENSE=	mpl-2.0

#DEPENDS+=	${PYPKGPREFIX}-mozfile>=1.2:../../wip/py-mozfile
#DEPENDS+=	${PYPKGPREFIX}-mozlog>=6.0:../../wip/py-mozlog
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
#TEST_DEPENDS+=	# TODO: wptserve>=0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
