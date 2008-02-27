# $NetBSD: Makefile,v 1.5 2008/02/27 17:51:31 smoppy Exp $

DISTNAME=	tmux-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)

NO_CONFIGURE=	yes
USE_NCURSES=	yes

# compat/strtonum.c: replace "tmux.h" with "../tmux.h"
SUBST_CLASSES+=		header
SUBST_STAGE.header=	pre-build
SUBST_MESSAGE.header=	Fixing distribution headers..
SUBST_FILES.header=	compat/strtonum.c
SUBST_SED.header=	-e "s,tmux.h,../tmux.h,"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmux ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tmux.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
