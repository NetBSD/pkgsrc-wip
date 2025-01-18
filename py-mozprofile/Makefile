# $NetBSD$

DISTNAME=	mozprofile-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/00/eb/9de383c0ccfa3ac7ca21fe5d8fd861579c83c119d72ae1fe2d25e787c5b3/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://firefox-source-docs.mozilla.org/mozbase/mozprofile.html
COMMENT=	Library to create and modify Mozilla application profiles
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mozfile>=1.2:../../wip/py-mozfile
DEPENDS+=	${PYPKGPREFIX}-mozlog>=6.0:../../wip/py-mozlog
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
#TEST_DEPENDS+=	# TODO: wptserve>=0

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
