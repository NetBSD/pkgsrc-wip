# $NetBSD: Makefile,v 1.1.1.1 2004/07/16 18:14:30 ppostma Exp $

MODNAME=		ftp
PKGREVISION=		# empty
CATEGORIES+=		net
COMMENT=		PHP5 extension for FTP access

USE_BUILDLINK3=		YES

.include "../../wip/php5/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
