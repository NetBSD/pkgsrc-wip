# $NetBSD: Makefile,v 1.2 2003/08/28 09:48:43 xtraeme Exp $
#

DISTNAME=	cgdb-0.3.2
CATEGORIES=	devel
MASTER_SITES=	http://66.35.250.221:80/sourceforge/cgdb/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNU_READLINE=	yes
USE_NCURSES=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cgdb
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cgdb

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
