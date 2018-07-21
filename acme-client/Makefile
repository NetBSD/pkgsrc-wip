# $NetBSD$

DISTNAME=	acme-client-portable-${GITHUB_TAG}
PKGNAME=	${DISTNAME:S/-portable//:S/VERSION_//:S/_/./g}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_PROJECT=	acme-client-portable
GITHUB_TAG=	VERSION_0_1_16

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/kristapsdz/acme-client/
COMMENT=	Secure Let's Encrypt client
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	acme-client.1
SUBST_FILES.paths+=	config.h
SUBST_FILES.paths+=	http.c
SUBST_FILES.paths+=	main.c
SUBST_SED.paths=	-e 's|/etc/ssl|${PKG_SYSCONFDIR}/ssl|g'
SUBST_SED.paths+=	-e 's|/etc/acme|${PKG_SYSCONFDIR}/acme|g'

.include "../../security/libressl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
