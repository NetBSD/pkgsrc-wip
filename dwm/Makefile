# $NetBSD: Makefile,v 1.2 2006/11/08 23:15:27 kh-p Exp $

DISTNAME=		dwm-2.1
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://dwm.suckless.org/
COMMENT=		Dynamic window manager

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dwm.1 ${PREFIX}/man/man1

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
