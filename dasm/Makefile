# $NetBSD: Makefile,v 1.2 2004/11/20 15:43:11 minskim Exp $
#

DISTNAME=	dasm212
PKGNAME=	dasm-2.12
CATEGORIES=	devel cross
MASTER_SITES=	http://members.cox.net/rcolbert/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	mor@linex.com
HOMEPAGE=	http://members.cox.net/rcolbert/dasm.htm
COMMENT=	Professional-grade multi-CPU cross-assembler for 6502, 6803 and 68HC11

NO_CONFIGURE:	YES

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/*.c ${WRKSRC}
	${MV} ${WRKDIR}/*.h ${WRKSRC}

do-build:
	@files/build.sh ${WRKSRC} ${CC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dasm ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
