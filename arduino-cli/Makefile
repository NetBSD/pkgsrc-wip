# $NetBSD$

DISTNAME=	arduino-cli-0.35.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://github.com/arduino/arduino-cli/
COMMENT=	Arduino command line tool
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	arduino-ctags>=5.8:../../wip/arduino-ctags
DEPENDS+=	arduino-dfu-discovery>=0.1.2:../../wip/arduino-dfu-discovery
DEPENDS+=	arduino-mdns-discovery>=1.0.9:../../wip/arduino-mdns-discovery
DEPENDS+=	arduino-serial-discovery>=1.4.0:../../wip/arduino-serial-discovery
DEPENDS+=	arduino-serial-monitor>=0.13.0:../../wip/arduino-serial-monitor
.endif

pre-build:
	${SED} -i 's|/usr/pkg|${PREFIX}|g' ${WRKSRC}/commands/instances.go

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
