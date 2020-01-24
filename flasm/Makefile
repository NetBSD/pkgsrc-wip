# $NetBSD: Makefile,v 1.5 2012/09/28 22:33:39 asau Exp $

DISTNAME=		flasm16src
PKGNAME=		flasm-1.6.1
CATEGORIES=		devel
MASTER_SITES=		http://www.nowrap.de/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://flasm.sourceforge.net/
COMMENT=		Flasm is a assembler/disassembler of Flash ActionScript bytecode

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
USE_TOOLS+=		gmake yacc

INSTALLATION_DIRS=	bin share/doc share/examples

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/flasm.html ${DESTDIR}${PREFIX}/share/doc
	${INSTALL_DATA} ${WRKSRC}/classic.css ${DESTDIR}${PREFIX}/share/doc
	${INSTALL_DATA} ${WRKSRC}/flasm.ini ${DESTDIR}${PREFIX}/share/examples

.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
