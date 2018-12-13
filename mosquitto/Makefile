# $NetBSD$

VERSION=	1.5.5
DISTNAME=	mosquitto-${VERSION}
CATEGORIES=	net
MASTER_SITES=	https://mosquitto.org/files/source/

#MAINTAINER=	amoibos@gmail.com
MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	epl-v1.0

USE_LANGUAGES+=	c c++
# Upstream documents that "unix" should use make, but Mac cmake.
# After asking and receiving no guidance, choose to always use cmake.
# https://github.com/eclipse/mosquitto/issues/1041
USE_CMAKE=	yes
USE_TOOLS+=	gmake

# config.mk is in theory used by only the non-cmake build.  Remove it,
# to force a failure if it somehow becomes used.
pre-configure:
	${RM} ${WRKSRC}/config.mk

CONF_FILES=	${PREFIX}/share/examples/mosquitto/pskfile.example \
		${PREFIX}/share/examples/mosquitto/pwfile.example \
		${PREFIX}/share/examples/mosquitto/mosquitto.conf \
		${PREFIX}/share/examples/mosquitto/aclfile.example

# The upstream code uses ldconfig.
# https://github.com/eclipse/mosquitto/issues/1048
SUBST_CLASSES+=			ldconfig
SUBST_STAGE.ldconfig=		pre-configure
SUBST_MESSAGE.ldconfig=		Removing non-portable ldconfig invocations
SUBST_FILES.ldconfig=		lib/CMakeLists.txt \
				lib/cpp/CMakeLists.txt \
				src/CMakeLists.txt
SUBST_SED.ldconfig=		-E -e '/EXEC_PROGRAM\(\/sbin\/ldconfig/d'

post-install:
	mkdir ${DESTDIR}${PREFIX}/share/examples/mosquitto
	${INSTALL_DATA}	${WRKSRC}/pskfile.example ${WRKSRC}/pwfile.example ${WRKSRC}/mosquitto.conf ${WRKSRC}/aclfile.example ${DESTDIR}${PREFIX}/share/examples/mosquitto

.include "../../devel/libuuid/buildlink3.mk"
# ?needed
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
