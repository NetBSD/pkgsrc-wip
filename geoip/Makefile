# $NetBSD: Makefile,v 1.4 2003/05/09 12:20:32 xtraeme Exp $
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
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

EGDIR=		${PREFIX}/share/examples/GeoIP
CONF_FILES=	${EGDIR}/GeoIP.conf ${PKG_SYSCONFDIR}/GeoIP.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${PKG_SYSCONFDIR}/GeoIP.conf \
		${EGDIR}/GeoIP.conf

.include "../../mk/bsd.pkg.mk"
