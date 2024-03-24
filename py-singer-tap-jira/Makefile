# $NetBSD$

DISTNAME=	tap-jira-2.2.0
PKGNAME=	${PYPKGPREFIX}-singer-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tap-jira/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/singer-io/tap-jira
COMMENT=	Singer Tap to extract data from the JIRA API
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-singer-python>=6.0.0:../../wip/py-singer-python

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# only for Python 3

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tap-jira singer-tap-jira${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
