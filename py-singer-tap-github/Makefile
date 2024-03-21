# $NetBSD$

DISTNAME=	tap-github-3.0.1
PKGNAME=	${PYPKGPREFIX}-singer-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tap-github/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/singer-io/tap-github
COMMENT=	Singer Tap to extract data from the GitHub API
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-backoff>=1.8.0:../../wip/py-backoff
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-singer-python>=5.12.1:../../wip/py-singer-python

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# only for Python 3

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tap-github singer-tap-github${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
