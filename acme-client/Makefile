# $NetBSD$

DISTNAME=	acme-client-0.1.15
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/kristapsdz/acme-client/
COMMENT=	Secure Let's Encrypt client
LICENSE=	modified-bsd

GITHUB_PROJECT=	acme-client-portable
GITHUB_TAG=	VERSION_${PKGVERSION_NOREV:S/./_/g}

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	${WRKSRC}/acme-client.1
SUBST_FILES.paths+=	${WRKSRC}/config.h
SUBST_FILES.paths+=	${WRKSRC}/http.c
SUBST_FILES.paths+=	${WRKSRC}/main.c
SUBST_SED.paths=	-e 's|/etc/ssl|${PKG_SYSCONFDIR}/ssl|g'
SUBST_SED.paths+=	-e 's|/etc/acme|${PKG_SYSCONFDIR}/acme|g'

.include "../../security/libressl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
