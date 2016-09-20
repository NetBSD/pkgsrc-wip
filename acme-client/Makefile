# $NetBSD$

DISTNAME=	acme-client-0.1.11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_PROJECT=	acme-client-portable
GITHUB_TAG=	VERSION_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/kristapsdz/acme-client/
COMMENT=	Secure Let's Encrypt client
LICENSE=	modified-bsd

USE_TOOLS=	gmake
MAKE_FILE=	GNUmakefile

.include "../../security/libressl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
