# $NetBSD: Makefile,v 1.1.1.1 2003/09/01 15:14:20 adrian_p Exp $

MODNAME=		openssl
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for openssl

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${PKGDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

LIBS+=			-lssl -lcrypto

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
