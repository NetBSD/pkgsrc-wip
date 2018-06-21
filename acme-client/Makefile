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
SUBST_FILES.paths=	${WRKSRC}/acme-client.1
SUBST_FILES.paths+=	${WRKSRC}/config.h
SUBST_FILES.paths+=	${WRKSRC}/http.c
SUBST_FILES.paths+=	${WRKSRC}/main.c
SUBST_FILES.paths+=	${WRKDIR}/acme-client.conf
SUBST_SED.paths=	-e 's|/etc/ssl|${PKG_SYSCONFDIR}/ssl|g'
SUBST_SED.paths+=	-e 's|/etc/acme|${PKG_SYSCONFDIR}/acme|g'

EGDIR=			share/examples/acme-client
INSTALLATION_DIRS+=	${EGDIR}

CONF_FILES+=	${EGDIR}/acme-client.conf ${PKG_SYSCONFDIR}/acme-client.conf

post-extract:
	${CP} ${FILESDIR}/acme-client.conf.in ${WRKDIR}/acme-client.conf

post-install:
	${INSTALL_DATA} ${WRKDIR}/acme-client.conf ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../security/libressl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
