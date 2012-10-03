# $NetBSD: Makefile,v 1.10 2012/10/03 15:09:55 asau Exp $

# Version based on CVS revision number.
DISTNAME=		mkdep-1.16
CATEGORIES=		devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		reed@reedmedia.net
COMMENT=		Fast mkdep

USE_FEATURES=		nbcompat

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkdep ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mkdep.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
