# $NetBSD$

GITHUB_PROJECT=	acme-client-portable
DISTNAME=	VERSION_0_1_11
PKGNAME=	acme-client-0.1.11
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=kristapsdz/acme-client-portable/}
COMMENT=	"A secure Let's Encrypt client"
LICENSE=	modified-bsd

USE_TOOLS=	gmake
MAKE_FILE=	GNUmakefile

WRKSRC=		${WRKDIR}/acme-client-portable-VERSION_0_1_11

.include "../../security/libressl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
