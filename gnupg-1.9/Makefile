# $NetBSD: Makefile,v 1.8 2004/10/14 22:31:01 johnrshannon Exp $
#

DISTNAME=		gnupg-1.9.11
PKGNAME=		gnupg2-1.9.11
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
COMMENT=		Utility programs that come with GnuPG 1.9 (experimental branch)

BUILD_USES_MSGFMT=      yes

USE_BUILDLINK3=         yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
GNU_CONFIGURE=          yes
USE_GNU_TOOLS+=         make
CRYPTO=                 yes
CONFIGURE_ARGS+=        --with-static-rnd=auto

TEST_TARGET=            check

.include "../../wip/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/libassuan/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../wip/pinentry/buildlink3.mk"
.include "../../wip/dirmngr/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
# must use pth rather than native pthreads
.include "../../devel/pth/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
