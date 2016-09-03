# $NetBSD$
PKGNAME=	mosquitto-1.4.10
DISTNAME=	${PKGNAME}
CATEGORIES=	net
MASTER_SITES=	http://mosquitto.org/files/source/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	eclipse-license

USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake gmake

post-install:
	mkdir ${DESTDIR}${PREFIX}/etc/mosquitto
	${INSTALL}	${WRKSRC}/pskfile.example ${WRKSRC}/pwfile.example ${WRKSRC}/mosquitto.conf ${WRKSRC}/aclfile.example ${DESTDIR}${PREFIX}/etc/mosquitto

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
