# $NetBSD: Makefile,v 1.4 2012/09/28 21:07:56 asau Exp $
#

DISTNAME=	distella
PKGNAME=	distella-2.10
CATEGORIES=	devel games cross emulators
MASTER_SITES=	http://members.cox.net/rcolbert/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	xmor61@users.sourceforge.net
HOMEPAGE=	http://members.cox.net/rcolbert/index.htm
COMMENT=	6502 Disassembler with Atari 2600 headers and cycle counting info

NO_CONFIGURE=		YES
EXTRACT_OPTS_ZIP=	-Laqo

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/*.c ${WRKSRC}
	${MV} ${WRKDIR}/*.txt ${WRKSRC}

do-build:
	( cd ${WRKSRC} ; ${CC} -o distella distella.c )

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/distella
	${INSTALL_DATA} ${WRKSRC}/distella.txt ${DESTDIR}${PREFIX}/share/doc/distella
	${INSTALL_PROGRAM} ${WRKSRC}/distella ${DESTDIR}${PREFIX}/bin
	@${ECHO} ""
	@${ECHO} ";======================================================================================;"
	@${ECHO} " BUG-NOTICE: Distella may core dump some machines if you do not specify any parameters."
	@${ECHO} ""
	@${ECHO} " Read '${PREFIX}/share/doc/distella/distella.txt' for detailed usage instructions..."
	@${ECHO} ";======================================================================================;"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
