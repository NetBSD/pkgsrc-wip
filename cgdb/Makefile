# $NetBSD: Makefile,v 1.6 2003/10/03 11:42:06 xtraeme Exp $
#

DISTNAME=	cgdb-0.3.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgdb/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNU_READLINE=	yes

CONFIGURE_ARGS+=	--with-curses

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cgdb
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cgdb

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
