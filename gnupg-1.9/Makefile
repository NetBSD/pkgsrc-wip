# $NetBSD: Makefile,v 1.1 2004/02/25 13:29:24 johnrshannon Exp $
#

DISTNAME=		gnupg-1.9.5
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/gnupg/
COMMENT=		GnuPG 1.9 is the experimental branch of GnuPG with support for S/MIME.

USE_BUILDLINK3=         yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
GNU_CONFIGURE=          yes
USE_GNU_TOOLS+=         make

.include "../libgpg-error/buildlink3.mk"
.include "../libgcrypt/buildlink3.mk"
.include "../libassuan/buildlink3.mk"
.include "../libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
