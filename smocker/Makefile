# $NetBSD$

DISTNAME=	smocker-0.18.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Thiht/}

# XXX: Release distfile is actually just a tar, not a tar.gz (probably
# XXX: accidentally).
RELEASE_DIST=		${DISTNAME}-release.tar
SITES.${RELEASE_DIST}=	-https://github.com/Thiht/smocker/releases/download/${PKGVERSION_NOREV}/smocker.tar.gz
DISTFILES=		${DEFAULT_DISTFILES} ${RELEASE_DIST}

EXTRACT_DIR.${RELEASE_DIST}=	${WRKSRC}/release

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://smocker.dev/
COMMENT=	Simple and efficient HTTP mock server and proxy
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.appName=smocker \
			-X main.buildVersion=${PKGVERSION_NOREV} \
			-X main.buildCommit= \
			-X main.buildDate='

PKG_SYSCONFSUBDIR=	smocker

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Adjust hardcoded paths
SUBST_FILES.paths+=	main.go
SUBST_VARS.paths=	PKG_SYSCONFDIR PREFIX

.include "go-modules.mk"

INSTALLATION_DIRS+=	share/smocker

# Remove binary to preserve only static files needed by -static-files option
post-extract:
	${RM} ${WRKSRC}/release/smocker

# Install also static files needed by -static-files option
post-install:
	${INSTALL_DATA} ${WRKSRC}/release/* ${DESTDIR}${PREFIX}/share/smocker

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
