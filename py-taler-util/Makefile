# $NetBSD$

DISTNAME=	taler-util-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/taler-util/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://git.taler.net/taler-util.git
COMMENT=	Util library for GNU Taler
LICENSE=	gnu-lgpl-v3 # or later

TEST_DEPENDS+=	py-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	py-future>=0:../../devel/py-future

WRKSRC=		${WRKDIR}/taler-util-0.6.2
USE_LANGUAGES=	# none

# Needs at least python 3.7
PYTHON_VERSIONS_INCOMPATIBLE=	27 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
