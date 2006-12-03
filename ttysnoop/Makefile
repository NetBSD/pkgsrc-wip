# $NetBSD: Makefile,v 1.10 2006/12/03 17:59:35 shattered Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoop ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoops ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ttysnoop.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${VARBASE}/spool/ttysnoop

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
