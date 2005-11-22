# $NetBSD: Makefile,v 1.1.1.1 2005/11/22 10:43:52 ghen Exp $

DISTNAME=		sockstat-1.0
CATEGORIES=		sysutils
DISTFILES=		# empty
MASTER_SITES=		# empty

MAINTAINER=		geert.hendrickx@ua.ac.be
COMMENT=		Tool to list open/connected sockets
HOMEPAGE=		#

# NetBSD 3.0 and newer have a native sockstat(1)
ONLY_FOR_PLATFORM=	NetBSD-[12]*-*

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
USE_LANGUAGES=		# empty

USE_TOOLS+=		perl:run
REPLACE_PERL=		sockstat.pl

do-extract:
	${CP} ${FILESDIR}/sockstat.pl ${WRKSRC}/${f}
	${CP} ${FILESDIR}/sockstat.1 ${WRKSRC}/${f}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sockstat.pl ${PREFIX}/bin/sockstat
	${INSTALL_MAN} ${WRKSRC}/sockstat.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
