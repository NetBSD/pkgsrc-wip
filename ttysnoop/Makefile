# $NetBSD: Makefile,v 1.1.1.1 2004/11/24 13:56:07 poppnk Exp $
#

DISTNAME=		ttysnoop-0.12c
CATEGORIES=		wip security
MASTER_SITES=${MASTER_SITE_SUNSITE:=utils/terminal/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://metalab.unc.edu/pub/Linux/utils/terminal/
COMMENT=		TTY snoop for GNU/Linux

USE_BUILDLINK3=		yes

SUBST_CLASSES=lib etc
SUBST_FILES.lib=Makefile
SUBST_STAGE.lib=configure
SUBST_SED.lib=-e 's,LIBS\t=, LIBS\ = -lcrypt,'
SUBST_FILES.etc=config.h
SUBST_STAGE.etc=configure
SUBST_SED.etc=-e 's,/etc,${PKG_SYSCONFDIR},'

ONLY_FOR_PLATFORM= Linux-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoop ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoops ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ttysnoop.8 ${PREFIX}/share/man/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ttysnoop/
	${INSTALL_DATA} ${WRKSRC}/snooptab.dist ${PREFIX}/share/examples/ttysnoop/
	${INSTALL_DATA_DIR} /var/spool/ttysnoop/

.include "../../mk/bsd.pkg.mk"
