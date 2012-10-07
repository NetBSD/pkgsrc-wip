# $NetBSD: Makefile,v 1.11 2012/10/07 17:10:07 asau Exp $
#

# TODO : wrong name ?
DISTNAME=		ttysnoop-0.12d.k26
PKGREVISION=	2
CATEGORIES=		sysutils
MASTER_SITES=		http://grad.icmc.usp.br/~duker/ttysnoop/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://grad.icmc.usp.br/~duker/ttysnoop/
COMMENT=		Snoop TTYs on Linux for kernels 2.6

SUBST_CLASSES+=etc
SUBST_FILES.etc=config.h
SUBST_STAGE.etc=configure
SUBST_SED.etc=-e 's,/var/,${VARBASE}/,'
SUBST_SED.etc+=-e 's,/etc,${PKG_SYSCONFDIR},'

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoop ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoops ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ttysnoop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${DESTDIR}${VARBASE}/spool/ttysnoop

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
