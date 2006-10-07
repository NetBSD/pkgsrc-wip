# $NetBSD: Makefile,v 1.1.1.1 2006/10/07 01:00:16 thomaspfaff Exp $
#

DISTNAME=		nbfc-0.1
CATEGORIES=		lang
MASTER_SITES=		http://koeln.ccc.de/prozesse/zombies/brainfuck/

MAINTAINER=		thomaspfaff@users.sourceforge.net
HOMEPAGE=		http://koeln.ccc.de/prozesse/zombies/brainfuck/
COMMENT=		Nbfc - the "new brainfuck compiler"

WRKSRC=			${WRKDIR}/nbfc-0.1
USE_TOOLS+=		gmake yacc

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/nbfc ${PREFIX}/bin
			${INSTALL_MAN} ${WRKSRC}/nbfc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
