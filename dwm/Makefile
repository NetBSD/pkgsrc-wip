# $NetBSD: Makefile,v 1.5 2007/04/03 19:58:30 cosmedbr Exp $

DISTNAME=		dwm-3.9
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
