# $NetBSD: Makefile,v 1.1.1.1 2011/04/14 09:44:42 bartoszkuzma Exp $
#

DISTNAME=		rsyslog-6.1.6
CATEGORIES=		sysutils
MASTER_SITES=		http://download.rsyslog.com/rsyslog/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.rsyslog.com/
COMMENT=		The enhanced syslogd for Unix
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-testbench
CONFIGURE_ARGS+=	--enable-mmnormalize

USE_TOOLS+=		pkg-config

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

.include "options.mk"

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

.include "../../wip/libee/buildlink3.mk"
.include "../../wip/libestr/buildlink3.mk"
.include "../../wip/liblognorm/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
