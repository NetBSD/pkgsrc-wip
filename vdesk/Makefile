# $NetBSD: Makefile,v 1.1.1.1 2007/07/11 10:44:14 bartoszkuzma Exp $
#

DISTNAME=	vdesk-1.2
CATEGORIES=	wm x11 wip
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://offog.org/code/vdesk.html
COMMENT=	Virtual desktop manager

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vdesk
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/README \
		${PREFIX}/share/doc/vdesk

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
