# $NetBSD: Makefile,v 1.7 2004/10/21 21:39:56 johnrshannon Exp $
#

DISTNAME=		libassuan-0.6.7
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/
COMMENT=		The IPC library used by some GnuPG related software

BUILDLINK_DEPENDS.libgpg-erro>= 1.0.0

USE_BUILDLINK3=		yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=         make

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
