# $NetBSD: Makefile,v 1.1.1.1 2003/09/24 00:44:08 jeremy-c-reed Exp $

# Version based on CVS revision number.
DISTNAME=		mkdep-1.16
CATEGORIES=		devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		reed@reedmedia.net
COMMENT=		Fast mkdep

NO_CHECKSUM=		# defined
NO_CONFIGURE=		YES
USE_BUILDLINK2=		# defined

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkdep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mkdep.1 ${PREFIX}/man/man1/

.include "../../pkgtools/libnbcompat/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
