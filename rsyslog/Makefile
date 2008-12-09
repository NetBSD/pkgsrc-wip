# $NetBSD: Makefile,v 1.14 2008/12/09 18:04:29 bartoszkuzma Exp $
#

DISTNAME=		rsyslog-3.21.9
CATEGORIES=		sysutils
MASTER_SITES=		http://download.rsyslog.com/rsyslog/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.rsyslog.com/
COMMENT=		The enhanced syslogd for Unix

GNU_CONFIGURE=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	tools/rsyslog.conf.5 tools/rsyslogd.8 tools/syslogd.c
SUBST_SED.paths=	-e "s|/etc/rsyslog.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
SUBST_SED.paths+=	-e "s|/etc/rsyslogd.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
SUBST_MESSAGE.paths=	Fixing paths.

DOCDIR=			${PREFIX}/share/doc/rsyslog

EGDIR=			${PREFIX}/share/examples/rsyslog
CONF_FILES=		${EGDIR}/rsyslog.conf ${PKG_SYSCONFDIR}/rsyslog.conf
RCD_SCRIPTS=		rsyslogd

PLIST_SRC=		PLIST.common

.include "options.mk"

PLIST_SRC+=		PLIST.common_end

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && pax -rw *.html ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rsyslog.conf ${EGDIR}/rsyslog.conf
.	if !empty(PKG_OPTIONS:Mmysql)
	${INSTALL_DATA} ${WRKSRC}/plugins/ommysql/createDB.sql \
		${EGDIR}/createDB-mysql.sql
.	endif
.	if !empty(PKG_OPTIONS:Mpgsql)
	${INSTALL_DATA} ${WRKSRC}/plugins/ompgsql/createDB.sql \
		${EGDIR}/createDB-pgsql.sql
.	endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
