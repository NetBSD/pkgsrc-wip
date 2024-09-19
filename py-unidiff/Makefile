# $NetBSD$

GITHUB_PROJECT=	python-unidiff
DISTNAME=	python-unidiff-0.5.4
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=matiasb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/unidiff
COMMENT=	Unified diff python parsing/metadata extraction library
LICENSE=	mit

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/python-//}

post-install:
	${RUN} ${MV} ${DESTDIR}${PREFIX}/bin/unidiff \
		${DESTDIR}${PREFIX}/bin/unidiff${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
