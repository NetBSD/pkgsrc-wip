# $NetBSD$

DISTNAME=	arduino-dfu-discovery-0.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arduino/}
GITHUB_PROJECT=	dfu-discovery
GITHUB_TAG=	v${PKGVERSION_NOREV}

DISTFILES=	${DEFAULT_DISTFILES}

DFU_UTIL=	dfu-util-0.11
DISTFILES+=	${DFU_UTIL}.tar.gz
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=dfu-util/files/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://github.com/arduino/dfu-discovery
COMMENT=	Arduino pluggable discovery for dfu devices
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	arduino15/packages/builtin/tools/dfu-discovery/${PKGVERSION_NOREV}

pre-build:
	${CP} -r ${WRKDIR}/${DFU_UTIL} ${WRKSRC}
	${CP} -f ${WRKSRC}/${DFU_UTIL}/src/dfuse_mem.c \
		${WRKSRC}/dfu-util_dfuse_mem.c
	${CP} -f ${WRKSRC}/${DFU_UTIL}/src/dfu_util.c \
		${WRKSRC}/dfu-util_dfu_util.c
	${CP} -f ${WRKSRC}/${DFU_UTIL}/src/quirks.c \
		${WRKSRC}/dfu-util_quirks.c
	${SED} -i 's/#cgo !darwin LDFLAGS: -L\/usr\/local\/lib -lusb-1.0/ \
		#cgo !darwin pkg-config: libusb-1.0/g' ${WRKSRC}/main.go

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/dfu-discovery \
		${DESTDIR}${PREFIX}/arduino15/packages/builtin/tools/dfu-discovery/${PKGVERSION_NOREV}

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
