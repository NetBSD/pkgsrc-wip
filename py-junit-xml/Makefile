# $NetBSD$

GITHUB_PROJECT=	python-junit-xml
GITHUB_TAG=	v1.9
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT:S/python-//}-${DISTNAME:S,^v,,}
CATEGORIES=	devel python
#forked from kyrus/python-junit-xml
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiaderouiche/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/kyrus/python-junit-xml
COMMENT=	Create JUnit XML test result documents read by tools such as Jenkins
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

WRKSRC=		${WRKDIR}/python-junit-xml-1.9

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
