# $NetBSD: Makefile,v 1.3 2009/09/25 09:32:00 bartoszkuzma Exp $
#

DISTNAME=		vdesk-1.2
CATEGORIES=		wm x11
MASTER_SITES=		http://offog.org/files/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://offog.org/code/vdesk.html
COMMENT=		Virtual desktop manager

GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vdesk
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/vdesk

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
