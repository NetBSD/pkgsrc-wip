# $NetBSD: Makefile,v 1.5 2013/10/23 11:10:25 fhajny Exp $
#

DISTNAME=		rsyslog-7.4.4
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.rsyslog.com/files/download/rsyslog/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.rsyslog.com/
COMMENT=		The enhanced syslogd for Unix
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-testbench
CONFIGURE_ARGS+=	--enable-mmnormalize
CONFIGURE_ARGS+=	--enable-cached-man-pages
CONFIGURE_ARGS+=	--enable-imdiag --enable-impstats --enable-omstdout
CONFIGURE_ARGS+=	--enable-diagtools --enable-usertools
CONFIGURE_ENV+=		RST2MAN=touch

USE_LIBTOOL=		yes
USE_TOOLS+=		flex pkg-config

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	tools/rsyslog.conf.5 tools/rsyslogd.8 tools/syslogd.c
SUBST_SED.paths=	-e "s|/etc/rsyslog.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
SUBST_SED.paths+=	-e "s|/etc/rsyslogd.conf|${PKG_SYSCONFDIR}/rsyslog.conf|g"
SUBST_MESSAGE.paths=	Fixing paths.

EGDIR=			${PREFIX}/share/examples/rsyslog
RCD_SCRIPTS=		rsyslogd

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rsyslog-example.conf ${DESTDIR}${EGDIR}/rsyslog.conf
.if !empty(PKG_OPTIONS:Mmysql)
	${INSTALL_DATA} ${WRKSRC}/plugins/ommysql/createDB.sql \
		${DESTDIR}${EGDIR}/createDB-mysql.sql
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
	${INSTALL_DATA} ${WRKSRC}/plugins/ompgsql/createDB.sql \
		${DESTDIR}${EGDIR}/createDB-pgsql.sql
.endif

.include "../../wip/libee/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.libestr+=	libestr>=0.1.5
.include "../../wip/libestr/buildlink3.mk"
.include "../../wip/liblognorm/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
