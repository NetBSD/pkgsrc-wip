# $NetBSD: Makefile,v 1.1.1.1 2003/04/24 23:56:47 xtraeme Exp $
#

DISTNAME=	GeoIP-1.1.9
PKGNAME=	geoip-1.1.9
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

#CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

post-install:
	${MV} ${PKG_SYSCONFDIR}/GeoIP.conf.default \
		${PKG_SYSCONFDIR}/GeoIP.conf

.include "../../mk/bsd.pkg.mk"
