# $NetBSD$

DISTNAME=	mozfile-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/ab/64/60b282b167a923aa8f3bdc819816592a55260dd71d72c45cc6a49fc67798/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Library of file utilities for use in Mozilla testing
LICENSE=	mpl-1.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
#TEST_DEPENDS+=	${PYPKGPREFIX}-wptserve>=3.0:../../wip/py-wptserve

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
