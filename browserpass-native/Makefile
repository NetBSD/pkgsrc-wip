# $NetBSD$

DISTNAME=	browserpass-native-3.0.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=browserpass/}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/browserpass/browserpass-native
COMMENT=	Browserpass native client app
LICENSE=	isc

EXTRACT_USING=	bsdtar

GITHUB_TAG=	${PKGVERSION_NOREV}

GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.0.mod
GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.1.mod
GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.1.zip
GO_MODULE_FILES+=	github.com/konsorten/go-windows-terminal-sequences/@v/v1.0.3.mod
GO_MODULE_FILES+=	github.com/konsorten/go-windows-terminal-sequences/@v/v1.0.3.zip
GO_MODULE_FILES+=	github.com/mattn/go-zglob/@v/v0.0.2.mod
GO_MODULE_FILES+=	github.com/mattn/go-zglob/@v/v0.0.2.zip
GO_MODULE_FILES+=	github.com/pmezard/go-difflib/@v/v1.0.0.mod
GO_MODULE_FILES+=	github.com/pmezard/go-difflib/@v/v1.0.0.zip
GO_MODULE_FILES+=	github.com/rifflock/lfshook/@v/v0.0.0-20180920164130-b9218ef580f5.mod
GO_MODULE_FILES+=	github.com/rifflock/lfshook/@v/v0.0.0-20180920164130-b9218ef580f5.zip
GO_MODULE_FILES+=	github.com/sirupsen/logrus/@v/v1.6.0.mod
GO_MODULE_FILES+=	github.com/sirupsen/logrus/@v/v1.6.0.zip
GO_MODULE_FILES+=	github.com/stretchr/objx/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/stretchr/objx/@v/v0.1.0.zip
GO_MODULE_FILES+=	github.com/stretchr/testify/@v/v1.2.2.mod
GO_MODULE_FILES+=	github.com/stretchr/testify/@v/v1.3.0.mod
GO_MODULE_FILES+=	github.com/stretchr/testify/@v/v1.3.0.zip
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190422165155-953cdadca894.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20200625212154-ddb9806d33ae.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20200625212154-ddb9806d33ae.zip

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
