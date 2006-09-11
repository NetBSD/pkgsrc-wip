# $NetBSD: Makefile,v 1.1.1.1 2006/09/11 18:00:38 kh-p Exp $

DISTNAME=		flasm16src
PKGNAME=		flasm-16
CATEGORIES=		devel
MASTER_SITES=		http://www.nowrap.de/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://flasm.sourceforge.net/
COMMENT=		Flasm is a assembler/disassembler of Flash ActionScript bytecode

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flasm ${PREFIX}/bin

.include "../../devel/flex/buildlink3.mk"
.include "../../devel/bison/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
