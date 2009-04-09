# $NetBSD: Makefile,v 1.8 2009/04/09 01:13:59 jsonn Exp $

# Version based on CVS revision number.
DISTNAME=		mkdep-1.16
CATEGORIES=		devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		reed@reedmedia.net
COMMENT=		Fast mkdep

USE_FEATURES=		nbcompat

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkdep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mkdep.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
