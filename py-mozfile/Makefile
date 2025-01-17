# $NetBSD$

DISTNAME=	mozfile-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/25/f8/a1f0076490d50dbe8bdcf15df97856a4734f459aaf0a4d42c64a11ab7231/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Library of file utilities for use in Mozilla testing
LICENSE=	mpl-1.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
#TEST_DEPENDS+=	${PYPKGPREFIX}-wptserve>=3.0:../../wip/py-wptserve

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
