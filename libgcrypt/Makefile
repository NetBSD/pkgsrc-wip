# $NetBSD: Makefile,v 1.1 2004/02/25 13:29:25 johnrshannon Exp $
#

DISTNAME=		libgcrypt-1.1.92
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/libgcrypt/

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/libgcrypt/
COMMENT=		SHORT_DESCRIPTION_OF_THE_PACKAGE

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=         make

.include "../libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
