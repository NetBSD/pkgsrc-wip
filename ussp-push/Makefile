# $NetBSD: Makefile,v 1.4 2012/11/25 23:32:31 othyro Exp $
#

DISTNAME=		ussp-push-0.4
CATEGORIES=		comms
MASTER_SITES=		http://xmailserver.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xmailserver.org/ussp-push.html
COMMENT=		OBEX object pusher for BlueZ
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ussp-push ${DESTDIR}${PREFIX}/bin

.include "../../devel/glib/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
