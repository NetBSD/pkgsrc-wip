# $NetBSD: Makefile,v 1.1.1.1 2004/11/10 18:33:30 ppostma Exp $

DISTNAME=		ftpsesame-0.95
CATEGORIES=		net
MASTER_SITES=		http://www.sentia.org/downloads/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://www.sentia.org/projects/ftpsesame/
COMMENT=                Automatic packet filter configurator for FTP

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
NO_CONFIGURE=		no

PKG_USERS=		proxy:nogroup::proxy\\ pseudo-user:${VARBASE}/chroot/proxy:/sbin/nologin

OWN_DIRS=		${VARBASE}/chroot/proxy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftpsesame ${PREFIX}/sbin/ftpsesame
	${INSTALL_MAN} ${WRKSRC}/ftpsesame.8 ${PREFIX}/man/man8/ftpsesame.8
	${INSTALL_MAN} ${WRKSRC}/ftpsesame.cat8 ${PREFIX}/man/cat8/ftpsesame.0

.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
