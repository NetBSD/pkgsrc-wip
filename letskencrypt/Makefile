# $NetBSD$

DISTNAME=	letsenkrypt-0.1.7
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_PROJECT=	letskencrypt-portable
GITHUB_TAG=	VERSION_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.0rg
HOMEPAGE=	https://github.com/kristapsdz/letskencrypt-portable/
COMMENT=	Secure Let's Encrypt client
LICENSE=	isc

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "../../security/libressl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
