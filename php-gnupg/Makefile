# $NetBSD$

MODNAME=		gnupg
PECL_VERSION=		1.4.0
CATEGORIES=		security

MAINTAINER=		tpaul@NetBSD.org
LICENSE=		modified-bsd
COMMENT=		Php module for interacting with gnupg

CONFIGURE_ARGS+=	--with-gnupg=${PREFIX}/include

INSTALLATION_DIRS+=	include/php/ext/gnupg

.include "../../security/gpgme/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
