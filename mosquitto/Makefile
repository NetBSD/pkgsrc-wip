# $NetBSD$
PKGNAME=	mosquitto-1.4.9
DISTNAME=	${PKGNAME}
CATEGORIES=	net
MASTER_SITES=	http://mosquitto.org/files/source/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	eclipse-license

USE_LANGUAGES+=	c c++
USE_TOOLS+=	cmake gmake

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
