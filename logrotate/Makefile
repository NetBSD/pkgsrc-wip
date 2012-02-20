# $NetBSD: Makefile,v 1.21 2012/02/20 13:00:03 obache Exp $
#

DISTNAME=		logrotate-3.8.1
#PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		https://fedorahosted.org/releases/l/o/logrotate/
MASTER_SITES+=		${MASTER_SITE_GENTOO:=distfiles/}
MASTER_SITES+=		${MASTER_SITE_FREEBSD:=distfiles/}

MAINTAINER=		ahp-nils@users.sourceforge.net
HOMEPAGE=		https://fedorahosted.org/logrotate/
COMMENT=		Daemon to rotate, compress, remove and mail system log files
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
.include "../../devel/popt/buildlink3.mk"

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
NO_EXPORT_CPP=		yes
MAKE_ENV+=		BASEDIR=${PREFIX}
MAKE_ENV+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=		INSTALL_MAN=${INSTALL_MAN:Q}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFBASE
DOCDIR=			share/doc/logrotate
TESTDIR=		test
EXAMPLES_DIR=		examples
EGDIR=			${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
CONF_FILES=		${EGDIR}/logrotate-default ${PKG_SYSCONFDIR}/logrotate.conf
INSTALLATION_DIRS=	sbin ${DOCDIR} ${DOCDIR}/${EXAMPLES_DIR} ${DOCDIR}/${TESTDIR} ${PKGMANDIR}/man8 ${PKGMANDIR}/man5 ${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/logrotate.d

SUBST_CLASSES+=		confs
SUBST_STAGE.confs=	post-patch
SUBST_MESSAGE.confs=	Fixing configuration files.
SUBST_FILES.confs=	${WRKSRC}/${EXAMPLES_DIR}/logrotate-default
SUBST_FILES.confs+=	${WRKSRC}/${EXAMPLES_DIR}/logrotate.cron
SUBST_VARS.confs=	PREFIX
SUBST_VARS.confs+=	VARBASE
SUBST_VARS.confs+=	PKG_SYSCONFDIR

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_MESSAGE.man=	Fixing man page.
SUBST_FILES.man+=	${WRKSRC}/logrotate.8
SUBST_VARS.man+=	PREFIX
SUBST_VARS.man+=	VARBASE
SUBST_VARS.man+=	PKG_SYSCONFDIR

MESSAGE_SUBST+=		DOCDIR=${DOCDIR}
MESSAGE_SUBST+=		EXAMPLES_DIR=${EXAMPLES_DIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/logrotate ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/${EXAMPLES_DIR}/logrotate-default ${DESTDIR}${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/${EXAMPLES_DIR}/logrotate.cron ${DESTDIR}${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${DESTDIR}${PREFIX}/${DOCDIR}/${TESTDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/logrotate.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/logrotate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
