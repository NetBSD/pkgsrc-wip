# $NetBSD: Makefile,v 1.6 2004/07/18 15:58:28 ppostma Exp $
#

DISTNAME=		gnupg-1.9.5
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
COMMENT=		GnuPG 1.9 is the experimental branch of GnuPG with support for S/MIME

USE_BUILDLINK3=         yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
GNU_CONFIGURE=          yes
USE_GNU_TOOLS+=         make

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../libassuan/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
