# $NetBSD$

DISTNAME=	arduino-mdns-discovery-1.0.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
GITHUB_PROJECT=	mdns-discovery
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://github.com/arduino/mdns-discovery
COMMENT=	MDNS (Bonjour) pluggable discovery tool
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	arduino15/packages/builtin/tools/mdns-discovery/${PKGVERSION_NOREV}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/mdns-discovery \
		${DESTDIR}${PREFIX}/arduino15/packages/builtin/tools/mdns-discovery/${PKGVERSION_NOREV}

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
