# $NetBSD$

VERSION=	1.6.1
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

CMAKE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples

# \todo Resolve what is an example vs. what might be used.
CONF_FILES=	${PREFIX}/share/examples/mosquitto/pskfile.example \
		${PREFIX}/share/examples/mosquitto/pwfile.example \
		${PREFIX}/share/examples/mosquitto/mosquitto.conf \
		${PREFIX}/share/examples/mosquitto/aclfile.example

# Fails; see https://github.com/eclipse/mosquitto/issues/1242
TEST_TARGET=	test
.include "../../devel/cunit/buildlink3.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
# ?needed
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
