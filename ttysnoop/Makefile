# $NetBSD: Makefile,v 1.12 2012/11/25 23:32:31 othyro Exp $
#

# TODO : wrong name ?
DISTNAME=		ttysnoop-0.12d.k26
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://grad.icmc.usp.br/~duker/ttysnoop/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://grad.icmc.usp.br/~duker/ttysnoop/
COMMENT=		Snoop TTYs on Linux for kernels 2.6

SUBST_CLASSES+=		etc
SUBST_FILES.etc=	config.h
SUBST_STAGE.etc=	configure
SUBST_SED.etc=		-e 's,/var/,${VARBASE}/,'
SUBST_SED.etc+=		-e 's,/etc,${PKG_SYSCONFDIR},'

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

ONLY_FOR_PLATFORM=	Linux-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoop ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoops ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ttysnoop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${DESTDIR}${VARBASE}/spool/ttysnoop

.include "../../mk/bsd.pkg.mk"
