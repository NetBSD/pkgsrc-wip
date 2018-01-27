# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:13 othyro Exp $
#

DISTNAME=		flexbackup-1.2.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://flexbackup.sourceforge.net/tarball/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://flexbackup.sourceforge.net/
COMMENT=		Flexible backup tool

USE_TOOLS+=		perl:run
REPLACE_PERL=		${WRKSRC}/flexbackup
NO_BUILD=		YES

SUBST_CLASSES+=		cfgpath
SUBST_MESSAGE.cfgpath =	Fixing hardcoded configuration file path.
SUBST_STAGE.cfgpath =	post-patch
SUBST_FILES.cfgpath =	flexbackup flexbackup.1 flexbackup.conf.5
SUBST_SED.cfgpath =	-e s,/etc/flexbackup.conf,${PKG_SYSCONFDIR}/flexbackup.conf,

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/flexbackup.conf ${PKG_SYSCONFDIR}/flexbackup.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf ${DESTDIR}${EGDIR}/flexbackup.conf
	${INSTALL_SCRIPT} ${WRKSRC}/flexbackup ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flexbackup.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/flexbackup.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/

.include "../../mk/bsd.pkg.mk"
