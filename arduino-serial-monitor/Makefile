# $NetBSD$

DISTNAME=	arduino-serial-monitor-0.13.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
GITHUB_PROJECT=	serial-monitor
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://github.com/arduino/serial-monitor
COMMENT=	Arduino pluggable monitor for serial ports
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	arduino15/packages/builtin/tools/serial-monitor/${PKGVERSION_NOREV}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/serial-monitor \
		${DESTDIR}${PREFIX}/arduino15/packages/builtin/tools/serial-monitor/${PKGVERSION_NOREV}

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
