# $NetBSD: Makefile,v 1.2 2003/05/09 04:05:52 xtraeme Exp $
#

DISTNAME=	GeoIP-1.1.9
PKGNAME=	${DISTNAME:S/GeoIP/geoip/}
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/c/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.maxmind.com/download/geoip/api/c/
COMMENT=	Find the country from any IP address

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

post-install:
	${MV} ${PKG_SYSCONFDIR}/GeoIP.conf.default \
		${PKG_SYSCONFDIR}/GeoIP.conf

.include "../../mk/bsd.pkg.mk"
