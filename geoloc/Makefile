# $NetBSD$

DISTNAME=	geoloc-${V}
V=		1.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=devnexen/}
HOMEPAGE=	https://github.com/devnexen/geoloc/
GITHUB_TAG=	v1.0
EXTRACT_SUFX=	.zip

CATEGORIES=	net

MAINTAINER=	devnexen@gmail.com
COMMENT=	The geoloc app is an unix socket which delivers geo data

LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS=	-DGEOLOC_INSTALL_PATH=${PKGDIR}

CONF_FILES=	${WRKSRC}/geolocd/geolocd.conf ${PREFIX}/etc/geolocd.conf

YACC=		yacc
USE_TOOLS=	yacc

post-extract:
		cd ${WRKSRC} && ${YACC} -o geolocd/y.tab.c geolocd/parse.y

pre-install:
		${MKDIR} ${DESTDIR}/${PREFIX}/sbin && cp ${WRKSRC}/build/geolocd ${DESTDIR}/${PREFIX}/sbin \
		&& cp ${WRKSRC}/build/geolocctl ${DESTDIR}/${PREFIX}/sbin && \
		${MKDIR} ${DESTDIR}/${PREFIX}/etc && cp ${WRKSRC}/geolocd/geolocd.conf ${DESTDIR}/${PREFIX}/etc && \
		${MKDIR} ${DESTDIR}/${PREFIX}/man8 && cp ${WRKSRC}/geolocd/geolocd.8 ${DESTDIR}/${PREFIX}/man8 && \
		${MKDIR} ${DESTDIR}/${PREFIX}/man5 && cp ${WRKSRC}/geolocd/geolocd.conf.5 ${DESTDIR}/${PREFIX}/man5 && \
		${MKDIR} ${DESTDIR}/${PREFIX}/man1 && cp ${WRKSRC}/geolocctl/geolocctl.1 ${DESTDIR}/${PREFIX}/man1

.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
