# $NetBSD: Makefile,v 1.1.1.1 2009/08/24 23:30:39 mbowie Exp $
#

MODNAME=		geoip
PECL_VERSION=		1.0.7
CATEGORIES=		net

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://pecl.php.net/package/geoip/
COMMENT=		PHP module to map IP address to geographic places

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../wip/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
