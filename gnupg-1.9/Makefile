# $NetBSD: Makefile,v 1.10 2004/10/17 16:16:11 johnrshannon Exp $
#

DISTNAME=		gnupg-1.9.11
PKGNAME=		gnupg2-1.9.11
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
COMMENT=		Utility programs that come with GnuPG 1.9 (experimental branch)

BUILD_USES_MSGFMT=      yes
BUILDLINK_DEPENDS.libgpg-erro>=	1.0.0

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=         yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
GNU_CONFIGURE=          yes
USE_GNU_TOOLS+=         make
CRYPTO=                 yes
CONFIGURE_ARGS+=        --with-static-rnd=auto
CONFIGURE_ARGS+=        --without-included-gettext

TEST_TARGET=            check

# We need gettext-lib >= 0.14.1 for NLS support
.include "../../wip/gettext-lib/buildlink3.mk"
GETTEXT_IS_TOO_OLD!=if ${PKG_ADMIN} pmatch 'gettext-lib < 0.14.1' gettext-lib ; then \
		${ECHO} "yes";	\
	else 	\
		${ECHO} "no";	\
	fi
 
.if GETTEXT_IS_TOO_OLD
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/libassuan/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../wip/pinentry/buildlink3.mk"
.include "../../wip/dirmngr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
