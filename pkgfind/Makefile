# $NetBSD: Makefile,v 1.1.1.1 2004/06/14 14:17:47 ppostma Exp $

DISTNAME=	pkgfind-20040614
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Find packages by package name in pkgsrc

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgfind ${PREFIX}/bin/pkgfind
	${INSTALL_MAN} ${WRKSRC}/pkgfind.1 ${PREFIX}/man/man1/pkgfind.1
	${INSTALL_MAN} ${WRKSRC}/pkgfind.cat1 ${PREFIX}/man/cat1/pkgfind.0

.include "../../mk/bsd.pkg.mk"
