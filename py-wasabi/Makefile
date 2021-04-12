# $NetBSD$


DISTNAME=	wasabi-v0.8.2
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ines/}
GITHUB_PROJECT=	wasabi

MAINTAINER=	lntl@disroot.org
HOMEPAGE=	https://ines.io
COMMENT=	A lightweight console printing and formatting toolkit
LICENSE=	mit

WRKSRC=	${$WRKDIR}/${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}/wasabi-0.8.2
USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
