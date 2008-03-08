# $NetBSD: Makefile,v 1.3 2008/03/08 20:13:49 dhowland Exp $
#

DISTNAME=		nbfc-0.1
CATEGORIES=		lang
MASTER_SITES=		http://koeln.ccc.de/ablage/brainfuck/

MAINTAINER=		thomaspfaff@users.sourceforge.net
HOMEPAGE=		http://koeln.ccc.de/ablage/brainfuck/
COMMENT=		Nbfc - the "new brainfuck compiler"

WRKSRC=			${WRKDIR}/nbfc-0.1
USE_TOOLS+=		gmake yacc

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/nbfc ${PREFIX}/bin
			${INSTALL_MAN} ${WRKSRC}/nbfc.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
