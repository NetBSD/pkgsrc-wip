# $NetBSD: Makefile,v 1.5 2006/04/20 13:36:35 cheusov Exp $
#

DISTNAME=	csup-snap-20060318
CATEGORIES=	net devel
MASTER_SITES=	http://www.mu.org/~mux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://www.mu.org/~mux/csup.html
COMMENT=	Rewrite of the CVSup file updating client in C

WRKSRC=		${WRKDIR}/csup

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/csup.1 ${PREFIX}/${PKGMANDIR}/man1/csup.1

.include "../../mk/bsd.pkg.mk"
