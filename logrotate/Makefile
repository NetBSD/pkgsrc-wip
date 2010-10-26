# $NetBSD: Makefile,v 1.9 2010/10/26 15:15:02 ahp-nils Exp $
#

DISTNAME=	logrotate-3.7.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	ahp-nils@users.sourceforge.net
HOMEPAGE=	https://fedorahosted.org/logrotate/
COMMENT=        Daemon to rotate, compress, remove and mail system log files
LICENSE=        gnu-gpl-v2

PKG_DESTDIR_SUPPORT=    user-destdir
.include "../../devel/popt/buildlink3.mk"

USE_TOOLS+=             gmake
USE_LIBTOOL=            yes
NO_EXPORT_CPP=          yes
MAKE_ENV+=              "BASEDIR=${PREFIX}"
MAKE_ENV+=              "INSTALL_PROGRAM=${INSTALL_PROGRAM}"
MAKE_ENV+=              "INSTALL_MAN=${INSTALL_MAN}"

DOCDIR=                 share/doc/logrotate
TESTDIR=                test
EXAMPLES_DIR=           examples
EGDIR=                  ${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
CONF_FILES=             ${EGDIR}/logrotate-default ${PKG_SYSCONFDIR}/logrotate.conf
INSTALLATION_DIRS=      sbin etc ${DOCDIR} ${DOCDIR}/${EXAMPLES_DIR} ${DOCDIR}/${TESTDIR} ${PKGMANDIR}/man8 ${PKGMANDIR}/man5 etc/logrotate.d

SUBST_CLASSES+=         confs
SUBST_STAGE.confs=      post-patch
SUBST_MESSAGE.confs=    Fixing configuration files.
SUBST_FILES.confs=      ${WRKSRC}/${EXAMPLES_DIR}/logrotate-default
SUBST_FILES.confs+=     ${WRKSRC}/${EXAMPLES_DIR}/logrotate.cron
SUBST_SED.confs=        -e "s|__PREFIX__|${PREFIX}|g"
SUBST_CLASSES+=         man
SUBST_STAGE.man=        post-patch
SUBST_MESSAGE.man=	Fixing man page.
SUBST_FILES.man=        ${WRKSRC}/logrotate.8
SUBST_SED.man=          -e "s|__PREFIX__|${PREFIX}|g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/logrotate ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${EXAMPLES_DIR}/logrotate-default ${DESTDIR}${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/${EXAMPLES_DIR}/logrotate.cron ${DESTDIR}${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${DESTDIR}${PREFIX}/${DOCDIR}/${TESTDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/logrotate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/logrotate.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
