# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 18:40:26 xtraeme Exp $
#

DISTNAME=	distella
PKGNAME=	distella-2.10
CATEGORIES=	devel games cross emulators
MASTER_SITES=	http://members.cox.net/rcolbert/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	mor@linex.com
HOMEPAGE=	http://members.cox.net/rcolbert/index.htm
COMMENT=	6502 Disassembler with Atari 2600 headers and cycle counting info

NO_CONFIGURE=	YES

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/*.c ${WRKSRC}
	${MV} ${WRKDIR}/*.txt ${WRKSRC}

do-build:
	( cd ${WRKSRC} ; ${CC} -o distella distella.c )

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/distella
	${INSTALL_DATA} ${WRKSRC}/distella.txt ${PREFIX}/share/doc/distella
	${INSTALL_PROGRAM} ${WRKSRC}/distella ${PREFIX}/bin
	@${ECHO} ""
	@${ECHO} ";======================================================================================;"
	@${ECHO} " BUG-NOTICE: Distella may core dump some machines if you do not specify any parameters."
	@${ECHO} ""
	@${ECHO} " Read '${PREFIX}/share/doc/distella/distella.txt' for detailed usage instructions..."
	@${ECHO} ";======================================================================================;"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
