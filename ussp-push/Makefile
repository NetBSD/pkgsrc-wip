# $NetBSD: Makefile,v 1.3 2012/10/07 17:30:35 asau Exp $
#

DISTNAME=		ussp-push-0.4
CATEGORIES=		comms
MASTER_SITES=		http://xmailserver.org/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://xmailserver.org/ussp-push.html
COMMENT=		OBEX object pusher for BlueZ

ONLY_FOR_PLATFORM=	Linux-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ussp-push ${DESTDIR}${PREFIX}/bin

.include "../../devel/glib/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
