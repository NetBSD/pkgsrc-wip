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

.if !empty(PKG_BUILD_OPTIONS.gpgme:Mgnupg2)
PKG_FAIL_REASON+=	"gpgme should be build with gnupg1 option"
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
