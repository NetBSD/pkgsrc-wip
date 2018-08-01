# $NetBSD$

VERSION=	1.4.15
DISTNAME=	mosquitto-${VERSION}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://mosquitto.org/files/source/

#MAINTAINER=	amoibos@gmail.com
MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	epl-v1.0

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

TEST_TARGET=	test

CONF_FILES=	share/examples/mosquitto/pskfile.example \
		share/examples/mosquitto/pwfile.example \
		share/examples/mosquitto/mosquitto.conf \
		share/examples/mosquitto/aclfile.example

post-install:
	mkdir ${DESTDIR}${PREFIX}/share/examples/mosquitto
	${INSTALL_DATA}	${WRKSRC}/pskfile.example ${WRKSRC}/pwfile.example ${WRKSRC}/mosquitto.conf ${WRKSRC}/aclfile.example ${DESTDIR}${PREFIX}/share/examples/mosquitto

.include "../../devel/libuuid/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
