# $NetBSD: Makefile,v 1.1 2009/12/14 01:43:26 genolopolis Exp $
#

PKGNAME=	mod_geoip2-1.2.5
DISTNAME=	mod_geoip2_1.2.5
CATEGORIES=	www
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/mod_geoip2/

PKG_APACHE_ACCEPTED=    apache2 apache22
USE_LANGUAGES+=         c++ c

.include "../../mk/apache.mk"
APACHE_MODULE_NAME= GeoIP
NO_CONFIGURE= yes

MAINTAINER= msporleder@gmail.com
HOMEPAGE=   http://www.maxmind.com/app/mod_geoip
COMMENT=    Apache module to interact with the MaxMind geoip database
LICENSE=    apache-1.1

do-build:

do-install:
	cd ${WRKSRC} && ${APXS} -i -L${LOCALBASE}/lib -I${LOCALBASE}/include -l ${APACHE_MODULE_NAME} -c mod_geoip.c

.include "../../net/GeoIP/buildlink3.mk"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
