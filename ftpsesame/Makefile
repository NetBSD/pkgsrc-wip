# $NetBSD: Makefile,v 1.10 2012/09/28 22:58:05 asau Exp $

DISTNAME=		ftpsesame-0.95
CATEGORIES=		net
MASTER_SITES=		http://www.sentia.org/downloads/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://www.sentia.org/projects/ftpsesame/
COMMENT=		Automatic packet filter configurator for FTP

NO_CONFIGURE=		yes

PKG_USERS=		proxy:nogroup::proxy\ pseudo-user:${VARBASE}/chroot/proxy:/sbin/nologin

OWN_DIRS=		${VARBASE}/chroot/proxy
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftpsesame ${DESTDIR}${PREFIX}/sbin/ftpsesame
	${INSTALL_MAN} ${WRKSRC}/ftpsesame.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/ftpsesame.8
	${INSTALL_MAN} ${WRKSRC}/ftpsesame.cat8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat8/ftpsesame.0

.include "../../mk/pf.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
