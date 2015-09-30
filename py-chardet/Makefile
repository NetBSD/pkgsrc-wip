# $NetBSD$

DISTNAME=			chardet-2.3.0
GITHUB_PROJECT=			chardet
PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=			devel
MASTER_SITES=			${MASTER_SITE_GITHUB:=chardet/}
EXTRACT_SUFX=			.zip

MAINTAINER=			gde@llew.me
HOMEPAGE=			http://chardet.github.io/
COMMENT=			Python 2/3 compatible character encoding detector

LICENSE=			gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	34 33 32 27 26
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON+=		setup.py
REPLACE_PYTHON+=		chardet/*.py

USE_LANGUAGES=			# none

WRKSRC=				${WRKDIR}/${DISTNAME}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
