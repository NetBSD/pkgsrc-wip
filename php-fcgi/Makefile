# $NetBSD: Makefile,v 1.5 2005/09/28 14:24:42 rillig Exp $
#

PKGNAME=		php-fcgi-${PHP_BASE_VERS}
COMMENT=		FastCGI interface for ${PKG_PHP}

LIBTOOL_OVERRIDE=

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.php"

CONFIGURE_ARGS+=	--enable-fastcgi

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php ${PREFIX}/bin/php-fcgi

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
