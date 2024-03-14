# $NetBSD$

DISTNAME=	arduino-esp8266-3.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=esp8266/}
GITHUB_PROJECT=	Arduino
GITHUB_TAG=	${PKGVERSION_NOREV}

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	lx106-hal-${LIBHALVER}.tar.gz
LIBHALVER=	e4bcc63c9c016e4f8848e7e8f512438ca857531d
SITES.lx106-hal-${LIBHALVER}.tar.gz= -https://github.com/tommie/lx106-hal/archive/${LIBHALVER}.tar.gz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://github.com/esp8266/Arduino/
COMMENT=	Arduino core for ESP8266 WiFi chip
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-esptool>=4.7.0:../../comms/py-esptool
DEPENDS+=	xtensa-lx106-elf-gcc-10.3.0{,nb*}:../../wip/xtensa-lx106-elf-gcc10

USE_TOOLS=	bash pax
NO_BUILD=	yes

CHECK_INTERPRETER=	no

INSTALLATION_DIRS=	arduino15/packages/hardware/esp8266/${PKGVERSION_NOREV}

post-patch:
	${SED} -i 's|{runtime.tools.xtensa-lx106-elf-gcc.path}/include|${LOCALBASE}/xtensa-lx106-elf/xtensa-lx106-elf/include|g' ${WRKSRC}/platform.txt
	${SED} -i 's|{runtime.tools.xtensa-lx106-elf-gcc.path}|${LOCALBASE}/xtensa-lx106-elf|g' ${WRKSRC}/platform.txt
	${SED} -i 's|{runtime.tools.python3.path}/python3|${PYTHONBIN}|g' ${WRKSRC}/platform.txt
	${SED} -i 's|{runtime.platform.path}/tools/python3/python3|${PYTHONBIN}|g' ${WRKSRC}/platform.txt
	${CP} -r ${WRKDIR}/lx106-hal-${LIBHALVER}/include/xtensa ${WRKSRC}/tools/sdk/include

do-install:
	cd ${WRKSRC} && pax -rw -pp -s '!.*/\..*!!' . ${DESTDIR}${PREFIX}/arduino15/packages/esp8266/hardware/esp8266/${PKGVERSION_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
