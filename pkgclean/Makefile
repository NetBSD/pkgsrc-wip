# $NetBSD: Makefile,v 1.1.1.1 2004/06/14 14:18:26 ppostma Exp $

DISTNAME=	pkgclean-20040614
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Quickly clean up all work directories in pkgsrc

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgclean ${PREFIX}/bin/pkgclean
	${INSTALL_MAN} ${WRKSRC}/pkgclean.1 ${PREFIX}/man/man1/pkgclean.1
	${INSTALL_MAN} ${WRKSRC}/pkgclean.cat1 ${PREFIX}/man/cat1/pkgclean.0

.include "../../mk/bsd.pkg.mk"
