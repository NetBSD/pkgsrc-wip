# $NetBSD$

DISTNAME=	browserpass-native-3.1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=browserpass/}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/browserpass/browserpass-native
COMMENT=	Browserpass native client app
LICENSE=	isc

EXTRACT_USING=	bsdtar

GITHUB_TAG=	v${PKGVERSION_NOREV}

.include "go-modules.mk"

GO_BUILD_PATTERN=	.
CHECK_RELRO_SKIP+=	bin/browserpass-native

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/examples/browserpass-native

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	browser-files/firefox-host.json
SUBST_SED.paths=	-e 's,%%replace%%,${PREFIX}/bin/browserpass-native,g'

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/browserpass-native ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/browser-files/firefox-host.json \
		${DESTDIR}${PREFIX}/share/examples/browserpass-native/com.github.browserpass.native.json

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
