# $NetBSD: Makefile,v 1.1.1.1 2009/08/24 20:38:27 mbowie Exp $
#

DISTNAME=		GeoIP-1.4.6
CATEGORIES=		net geography
MASTER_SITES=		http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://www.maxmind.com/app/c/
COMMENT=		Find the country that any IP address or hostname originates from

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONF_FILES=		${WRKSRC}/conf/GeoIP.conf.default ${PKG_SYSCONFDIR}/GeoIP.conf

.include "../../mk/bsd.pkg.mk"
