# $NetBSD$

GITHUB_PROJECT=	caddy
DISTNAME=	v0.8.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	wip www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mholt/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=mholt/caddy/}
COMMENT=	general-purpose web server
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none

BUILD_DEPENDS+=         go>=1.6:../../lang/go
USE_TOOLS=	bash

do-build:
	cd ${WRKSRC} && ${BASH} ./build.bash


.include "../../mk/bsd.pkg.mk"
