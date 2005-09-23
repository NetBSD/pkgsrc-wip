# $NetBSD: Makefile,v 1.1.1.1 2005/09/23 03:00:43 poppnk Exp $
#

DISTNAME=		flexbackup-1.2.1
CATEGORIES=		wip sysutils
MASTER_SITES=		http://flexbackup.sourceforge.net/tarball/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://flexbackup.sourceforge.net/
COMMENT=		Flexible backup tool

USE_PERL5=		YES
REPLACE_PERL=		${WRKSRC}/flexbackup
NO_BUILD=		YES

SUBST_CLASSES+=		cfgpath
SUBST_MESSAGE.cfgpath = "Fixing hardcoded configuration file path."
SUBST_STAGE.cfgpath = 	post-patch
SUBST_FILES.cfgpath = 	flexbackup flexbackup.1 flexbackup.conf.5
SUBST_SED.cfgpath = 	-e s,/etc/flexbackup.conf,${PREFIX}/etc/flexbackup.conf,

do-install:
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf ${PREFIX}/etc/flexbackup.conf
	${INSTALL_SCRIPT} ${WRKSRC}/flexbackup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flexbackup.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/flexbackup.conf.5 ${PREFIX}/man/man5/

.include "../../mk/bsd.pkg.mk"
