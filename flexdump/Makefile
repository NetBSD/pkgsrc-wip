# $NetBSD: Makefile,v 1.5 2006/03/14 01:27:59 jlamwww Exp $
#

DISTNAME=		flexbackup-1.2.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://flexbackup.sourceforge.net/tarball/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://flexbackup.sourceforge.net/
COMMENT=		Flexible backup tool

USE_TOOLS+=		perl5:run
REPLACE_PERL=		${WRKSRC}/flexbackup
NO_BUILD=		YES

SUBST_CLASSES+=		cfgpath
SUBST_MESSAGE.cfgpath = Fixing hardcoded configuration file path.
SUBST_STAGE.cfgpath = 	post-patch
SUBST_FILES.cfgpath = 	flexbackup flexbackup.1 flexbackup.conf.5
SUBST_SED.cfgpath = 	-e s,/etc/flexbackup.conf,${PKG_SYSCONFDIR}/flexbackup.conf,

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/flexbackup.conf ${PKG_SYSCONFDIR}/flexbackup.conf

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf ${EGDIR}/flexbackup.conf
	${INSTALL_SCRIPT} ${WRKSRC}/flexbackup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flexbackup.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/flexbackup.conf.5 ${PREFIX}/man/man5/

.include "../../mk/bsd.pkg.mk"
