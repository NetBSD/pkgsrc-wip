# $NetBSD: Makefile,v 1.1 2004/02/25 13:29:25 johnrshannon Exp $
#

DISTNAME=		libassuan-0.6.4
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/
COMMENT=		The IPC library used by some GnuPG related software.

USE_BUILDLINK3=		yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=         make

.include "../libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
