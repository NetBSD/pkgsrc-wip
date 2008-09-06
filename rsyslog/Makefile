# $NetBSD: Makefile,v 1.12 2008/09/06 20:53:19 thomasklausner Exp $
#

DISTNAME=		rsyslog-3.21.2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rsyslog/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.rsyslog.com/
COMMENT=		The enhanced syslogd for Unix

GNU_CONFIGURE=		yes

#SUBST_CLASSES+=		paths
#SUBST_STAGE.paths=	pre-configure
#SUBST_FILES.paths=	rsyslog.conf.5 rsyslogd.8 sample.conf syslogd.c
#SUBST_SED.paths=	-e "s|/etc/rsyslog.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
#SUBST_SED.paths+=	-e "s|/etc/rsyslogd.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
#SUBST_MESSAGE.paths=	Fixing paths.

EGDIR=			${PREFIX}/share/examples/rsyslog
CONF_FILES=		${EGDIR}/rsyslog.conf ${PKG_SYSCONFDIR}/rsyslog.conf
RCD_SCRIPTS=		rsyslogd

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${PREFIX}/share/doc/rsyslog
	${INSTALL_DATA} ${WRKSRC}/plugins/ommysql/createDB.sql ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rsyslog.conf ${EGDIR}/rsyslog.conf
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} bugs.html features.html history.html \
				how2help.html install.html manual.html \
				property_replacer.html rsyslog_conf.html \
				rsyslog_mysql.html rsyslog_php_syslog_ng.html \
				rsyslog_stunnel.html status.html \
				version_naming.html \
			${PREFIX}/share/doc/rsyslog

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
