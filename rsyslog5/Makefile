# $NetBSD: Makefile,v 1.6 2012/02/13 13:50:13 bartoszkuzma Exp $
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

USE_TOOLS+=		pax pkg-config

BUILD_DEFS+=		VARBASE

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

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_MESSAGE.conf=	Adjust configuration file
SUBST_FILES.conf=	rsyslog.conf
SUBST_SED.conf=		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'
SUBST_SED.conf+=	-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.conf+=	-e 's,@RSYSLOG_SYSMOD@,im${RSYSLOG_SYSMOD},'
SUBST_SED.conf+=	-e 's,@VARBASE@,${VARBASE},'

post-extract:
	${RUN} ${CP} ${FILESDIR}/rsyslog.conf ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc && pax -rw *.html ${DESTDIR}${DOCDIR}
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
