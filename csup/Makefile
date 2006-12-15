# $NetBSD: Makefile,v 1.8 2006/12/15 01:57:41 netcap Exp $
#

DISTNAME=	csup-snap-20060318
CATEGORIES=	net devel
MASTER_SITES=	http://www.mu.org/~mux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://www.mu.org/~mux/csup.html
COMMENT=	Rewrite of the CVSup file updating client in C

WRKSRC=		${WRKDIR}/csup

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CFLAGS+=    ${PTHREAD_CFLAGS}
LDFLAGS+=   ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/csup.1 ${PREFIX}/${PKGMANDIR}/man1/csup.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
