# $NetBSD: Makefile,v 1.9 2004/10/15 22:18:18 johnrshannon Exp $
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
CONFIGURE_ARGS+=	--disable-threads

TEST_TARGET=            check

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/libassuan/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../wip/pinentry/buildlink3.mk"
.include "../../wip/dirmngr/buildlink3.mk"
.include "../../wip/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
