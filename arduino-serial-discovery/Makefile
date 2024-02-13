# $NetBSD$

DISTNAME=	arduino-serial-discovery-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
GITHUB_PROJECT=	serial-discovery
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://github.com/arduino/serial-discovery
COMMENT=	Arduino pluggable discovery for serial ports
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	arduino15/packages/builtin/tools/serial-discovery/${PKGVERSION_NOREV}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/serial-discovery \
		${DESTDIR}${PREFIX}/arduino15/packages/builtin/tools/serial-discovery/${PKGVERSION_NOREV}

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
