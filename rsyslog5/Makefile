# $NetBSD: Makefile,v 1.5 2012/02/12 20:37:01 bartoszkuzma Exp $
#

DISTNAME=		rsyslog-5.8.7
CATEGORIES=		sysutils
MASTER_SITES=		http://www.rsyslog.com/files/download/rsyslog/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.rsyslog.com/
COMMENT=		The enhanced syslogd for Unix
LICENSE=		gnu-gpl-v3

CONFLICTS=		rsyslog-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-testbench

USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	tools/rsyslog.conf.5 tools/rsyslogd.8 tools/syslogd.c
SUBST_SED.paths=	-e "s|/etc/rsyslog.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
SUBST_SED.paths+=	-e "s|/etc/rsyslogd.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"

DOCDIR=			${PREFIX}/share/doc/rsyslog

EGDIR=			${PREFIX}/share/examples/rsyslog
CONF_FILES=		${EGDIR}/rsyslog.conf ${PKG_SYSCONFDIR}/rsyslog.conf
RCD_SCRIPTS=		rsyslogd

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

SUBST_CLASSES+=		sysmod
SUBST_STAGE.sysmod=	post-patch
SUBST_MESSAGE.sysmod=	Setting system/kernel logging module
SUBST_FILES.sysmod=	rsyslog.conf
SUBST_SED.sysmod=	-e 's,@RSYSLOG_SYSMOD@,im${RSYSLOG_SYSMOD},'

post-install:
	# ${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	# cd ${WRKSRC}/doc && pax -rw *.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rsyslog.conf ${DESTDIR}${EGDIR}/rsyslog.conf
.	if !empty(PKG_OPTIONS:Mmysql)
	${INSTALL_DATA} ${WRKSRC}/plugins/ommysql/createDB.sql \
		${DESTDIR}${EGDIR}/createDB-mysql.sql
.	endif
.	if !empty(PKG_OPTIONS:Mpgsql)
	${INSTALL_DATA} ${WRKSRC}/plugins/ompgsql/createDB.sql \
		${DESTDIR}${EGDIR}/createDB-pgsql.sql
.	endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
