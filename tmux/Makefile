# $NetBSD: Makefile,v 1.7 2008/12/26 21:52:09 fulviociriaco Exp $

DISTNAME=	tmux-0.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)

NO_CONFIGURE=	yes
USE_NCURSES=	yes

INSTALLATION_DIRS=	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 ${DESTDIR}${PREFIX}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmux ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tmux.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
