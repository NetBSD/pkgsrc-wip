# $NetBSD: Makefile,v 1.4 2012/09/03 16:01:26 shindenmorr Exp $
#

DISTNAME=		nbfc-0.1
CATEGORIES=		lang
MASTER_SITES=		http://koeln.ccc.de/ablage/brainfuck/

MAINTAINER=		thomaspfaff@users.sourceforge.net
HOMEPAGE=		http://koeln.ccc.de/ablage/brainfuck/
COMMENT=		Nbfc - the "new brainfuck compiler"

WRKSRC=			${WRKDIR}/nbfc-0.1
USE_TOOLS+=		gmake yacc
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/nbfc ${DESTDIR}${PREFIX}/bin
			${INSTALL_MAN} ${WRKSRC}/nbfc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
