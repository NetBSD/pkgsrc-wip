# $NetBSD: Makefile,v 1.1.1.1 2006/11/08 22:51:22 kh-p Exp $

DISTNAME=		dwm-2.1
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://dwm.suckless.org/
COMMENT=		Dynamic window manager

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dwm.1 ${PREFIX}/share/man

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
