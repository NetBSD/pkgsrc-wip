# $NetBSD: Makefile,v 1.1.1.1 2005/11/21 20:50:32 bartoszkuzma Exp $
#

DISTNAME=		rsyslog-1.0.3
CATEGORIES=		sysutils
MASTER_SITES=		http://download.adiscon.com/rsyslog/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.rsyslog.com/
COMMENT=		Rsyslog, the enhanced syslogd for Unix

MAKEFILE=		master.make
VPATH=			./ # Required for master.make.

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	rsyslog.conf.5 rsyslogd.8 sample.conf syslogd.c
SUBST_SED.paths=	-e "s|/etc/rsyslog.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g" -e "s|/etc/rsyslogd.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
SUBST_MESSAGE.paths=	"Fixing paths."

USE_PKGINSTALL=		yes
EGDIR=			${PREFIX}/share/examples/rsyslog
CONF_FILES=		${EGDIR}/rsyslog.conf ${PKG_SYSCONFDIR}/rsyslog.conf
RCD_SCRIPTS=		rsyslogd

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syslogd ${PREFIX}/sbin/rsyslogd
	${INSTALL_MAN} ${WRKSRC}/rsyslogd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/rsyslog.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${EGDIR} ${PREFIX}/share/doc/rsyslog
	${INSTALL_DATA} ${WRKSRC}/createDB.sql ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.conf ${EGDIR}/rsyslog.conf
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} bugs.html features.html history.html \
				how2help.html install.html manual.html \
				property_replacer.html rsyslog_conf.html \
				rsyslog_mysql.html rsyslog_php_syslog_ng.html \
				rsyslog_stunnel.html status.html \
				version_naming.html \
			${PREFIX}/share/doc/rsyslog

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
