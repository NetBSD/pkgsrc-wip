# $NetBSD: Makefile,v 1.3 2004/02/13 22:06:57 minskim Exp $
#

DISTNAME=	atasm103
PKGNAME=        atasm-1.03
CATEGORIES=	devel cross emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atasm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/atasm/
COMMENT=	Cross-assembler for 6502 optimized to code for Atari 8 bit computers

NO_CONFIGURE=   YES
WRKSRC=         ${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=	YES

DOCDIR=		${PREFIX}/share/doc/atasm

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/atasm ${PREFIX}/bin/atasm
	${SED} -e 's,%%DOCDIR%%,${DOCDIR},g' < ${WRKSRC}/atasm.1.in > ${WRKSRC}/atasm.1
	${INSTALL_DATA} ${WRKSRC}/atasm.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/atasm.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
