# $NetBSD: Makefile,v 1.2 2009/08/25 03:26:42 mbowie Exp $
#

MODNAME=		geoip
PECL_VERSION=		1.0.7
CATEGORIES=		net geography

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://pecl.php.net/package/geoip/
COMMENT=		PHP module to map IP address to geographic places

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
