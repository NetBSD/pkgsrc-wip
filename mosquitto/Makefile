# $NetBSD$
VERSION=	1.4.10
PKGREVISION=	1
PKGNAME=	mosquitto-${VERSION}
DISTNAME=	${PKGNAME}
CATEGORIES=	net
MASTER_SITES=	http://mosquitto.org/files/source/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	eclipse-license

USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake gmake

CONF_FILES=	share/examples/mosquitto/pskfile.example \
		share/examples/mosquitto/pwfile.example \
		share/examples/mosquitto/mosquitto.conf \
		share/examples/mosquitto/aclfile.example

post-install:
	mkdir ${DESTDIR}${PREFIX}/share/examples/mosquitto
	${INSTALL_DATA}	${WRKSRC}/pskfile.example ${WRKSRC}/pwfile.example ${WRKSRC}/mosquitto.conf ${WRKSRC}/aclfile.example ${DESTDIR}${PREFIX}/share/examples/mosquitto

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
