# $NetBSD$

GITHUB_PROJECT=	dub
GITHUB_TAG=	v1.21.0
DISTNAME=	v1.21.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dlang/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/dlang/dub/
COMMENT=	Package and build management system for D
LICENSE=	mit

WRKSRC=		${WRKDIR}/dub-1.21.0
USE_LANGUAGES=	c

INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC} && ldmd2 -run build.d

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dub ${DESTDIR}${PREFIX}/bin

BUILD_DEPENDS+=	ldc>1.0:../../wip/ldc

.include "../../mk/bsd.pkg.mk"
