# $NetBSD$


DISTNAME=	ml-datasets-v0.2.0
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=explosion/}
GITHUB_PROJECT=	ml-datasets

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://github.com/explosion/ml-datasets/
COMMENT=	various machine learning datasets for testing and example scripts
LICENSE=	mit

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}/ml-datasets-0.2.0
USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
