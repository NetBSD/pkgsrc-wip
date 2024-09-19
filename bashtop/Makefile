# $NetBSD$

GITHUB_PROJECT=	bashtop
GITHUB_TAG=	v0.8.14
DISTNAME=	v0.8.14
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/aristocratos/bashtop/
COMMENT=	Linux resource monitor
LICENSE=	apache-2.0

ONLY_FOR_PLATFORM=	Linux-*-*

WRKSRC=		${WRKDIR}/bashtop-0.8.14
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bashtop ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
