# $NetBSD: Makefile,v 1.3 2004/04/25 18:26:25 blef Exp $
#

DISTNAME=	memtester-2.93.1
CATEGORIES=	security
MASTER_SITES=	http://www.qcc.ca/~charlesc/software/memtester/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.qcc.ca/~charlesc/software/memtester/
COMMENT=	Utility for testing the memory subsystem

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memtest ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/memtest.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
