# $NetBSD: Makefile,v 1.2 2011/04/14 02:47:31 genolopolis Exp $
#

DISTNAME=	mod_geoip2_1.2.5
PKGNAME=	mod_geoip2-1.2.5
CATEGORIES=	www
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/mod_geoip2/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://www.maxmind.com/app/mod_geoip
COMMENT=	Apache module to interact with the MaxMind geoip database
LICENSE=	apache-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/apache.mk"
APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_geoip.so
PKG_APACHE_ACCEPTED=	apache2 apache22
NO_CONFIGURE=	yes
CPPFLAGS+=	-I${DESTDIR}/include
LDFLAGS+=	-L${DESTDIR}/lib -lGeoIP

pre-install:
	cp ${WRKDIR}/${DISTNAME}/.libs/mod_geoip.so ${WRKDIR}/${DISTNAME}/

.include "../../www/apache/module.mk"
.include "../../net/GeoIP/buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
