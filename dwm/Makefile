# $NetBSD: Makefile,v 1.4 2007/01/07 09:16:00 rillig Exp $

DISTNAME=		dwm-2.1
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dwm.suckless.org/
COMMENT=		Dynamic window manager

NO_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dwm.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
