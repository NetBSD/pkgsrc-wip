# $NetBSD: Makefile,v 1.7 2012/10/07 17:41:41 asau Exp $
#

DISTNAME=		vdesk-1.2
PKGREVISION=		2
CATEGORIES=		wm x11
MASTER_SITES=		http://offog.org/files/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://offog.org/code/vdesk.html
COMMENT=		Virtual desktop manager

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vdesk
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/vdesk

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
