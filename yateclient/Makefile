# $NetBSD: Makefile,v 1.1 2013/06/10 12:33:30 othyro Exp $

DISTNAME=	yate-4.2.0-2
PKGNAME=	${DISTNAME:S/-/client-/1:S/-2/.2/1}
CATEGORIES=	net
MASTER_SITES=	http://yate.null.ro/tarballs/yate4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yate.null.ro/tarballs/yate4/
COMMENT=	Instant Messenger and a SoftPhone
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/yate
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--prefix=${PREFIX}
PKGCONFIG_OVERRIDE+=	yate.pc.in

.include "../../mk/bsd.fast.prefs.mk"

LIBS+=			${LIBOSSAUDIO}
SUBST_CLASSES+=		moc
SUBST_FILES.moc=	clients/qt4/Makefile modules/Makefile
SUBST_MESSAGE.moc=	Fixing MOC path.
SUBST_SED.moc=		-e "s|MOC := moc|MOC := ${QTDIR}/bin/moc|1"
SUBST_STAGE.moc=	post-configure

EGDIR=			share/examples/yate
CONF_FILES+=		${EGDIR}/accfile.conf \
				${PKG_SYSCONFDIR}/yate/accfile.conf
CONF_FILES+=		${EGDIR}/analog.conf ${PKG_SYSCONFDIR}/yate/analog.conf
CONF_FILES+=		${EGDIR}/cache.conf ${PKG_SYSCONFDIR}/yate/cache.conf
CONF_FILES+=		${EGDIR}/callcounters.conf \
				${PKG_SYSCONFDIR}/yate/callcounters.conf
CONF_FILES+=		${EGDIR}/callfork.conf \
				${PKG_SYSCONFDIR}/yate/callfork.conf
CONF_FILES+=		${EGDIR}/camel_map.conf \
				${PKG_SYSCONFDIR}/yate/camel_map.conf
CONF_FILES+=		${EGDIR}/ccongestion.conf \
				${PKG_SYSCONFDIR}/yate/ccongestion.conf
CONF_FILES+=		${EGDIR}/cdrbuild.conf \
				${PKG_SYSCONFDIR}/yate/cdrbuild.conf
CONF_FILES+=		${EGDIR}/cdrfile.conf \
				${PKG_SYSCONFDIR}/yate/cdrfile.conf
CONF_FILES+=		${EGDIR}/ciscosm.conf \
				${PKG_SYSCONFDIR}/yate/ciscosm.conf
CONF_FILES+=		${EGDIR}/clustering.conf \
				${PKG_SYSCONFDIR}/yate/clustering.conf
CONF_FILES+=		${EGDIR}/cpuload.conf \
				${PKG_SYSCONFDIR}/yate/cpuload.conf
CONF_FILES+=		${EGDIR}/dbpbx.conf ${PKG_SYSCONFDIR}/yate/dbpbx.conf
CONF_FILES+=		${EGDIR}/dsoundchan.conf \
				${PKG_SYSCONFDIR}/yate/dsoundchan.conf
CONF_FILES+=		${EGDIR}/enumroute.conf \
				${PKG_SYSCONFDIR}/yate/enumroute.conf
CONF_FILES+=		${EGDIR}/eventlogs.conf \
				${PKG_SYSCONFDIR}/yate/eventlogs.conf
CONF_FILES+=		${EGDIR}/extmodule.conf \
				${PKG_SYSCONFDIR}/yate/extmodule.conf
CONF_FILES+=		${EGDIR}/filetransfer.conf \
				${PKG_SYSCONFDIR}/yate/filetransfer.conf
CONF_FILES+=		${EGDIR}/gvoice.conf ${PKG_SYSCONFDIR}/yate/gvoice.conf
CONF_FILES+=		${EGDIR}/h323chan.conf \
				${PKG_SYSCONFDIR}/yate/h323chan.conf
CONF_FILES+=		${EGDIR}/heartbeat.conf \
				${PKG_SYSCONFDIR}/yate/heartbeat.conf
CONF_FILES+=		${EGDIR}/isupmangler.conf \
				${PKG_SYSCONFDIR}/yate/isupmangler.conf
CONF_FILES+=		${EGDIR}/jabberclient.conf \
				${PKG_SYSCONFDIR}/yate/jabberclient.conf
CONF_FILES+=		${EGDIR}/jabberserver.conf \
				${PKG_SYSCONFDIR}/yate/jabberserver.conf
CONF_FILES+=		${EGDIR}/javascript.conf \
				${PKG_SYSCONFDIR}/yate/javascript.conf
CONF_FILES+=		${EGDIR}/jbfeatures.conf \
				${PKG_SYSCONFDIR}/yate/jbfeatures.conf
CONF_FILES+=		${EGDIR}/lateroute.conf \
				${PKG_SYSCONFDIR}/yate/lateroute.conf
CONF_FILES+=		${EGDIR}/lksctp.conf \
				${PKG_SYSCONFDIR}/yate/lksctp.conf
CONF_FILES+=		${EGDIR}/mgcpca.conf \
				${PKG_SYSCONFDIR}/yate/mgcpca.conf
CONF_FILES+=		${EGDIR}/mgcpgw.conf \
				${PKG_SYSCONFDIR}/yate/mgcpgw.conf
CONF_FILES+=		${EGDIR}/moh.conf ${PKG_SYSCONFDIR}/yate/moh.conf
CONF_FILES+=		${EGDIR}/monitoring.conf \
				${PKG_SYSCONFDIR}/yate/monitoring.conf
CONF_FILES+=		${EGDIR}/mux.conf ${PKG_SYSCONFDIR}/yate/mux.conf
CONF_FILES+=		${EGDIR}/mysqldb.conf \
				${PKG_SYSCONFDIR}/yate/mysqldb.conf
CONF_FILES+=		${EGDIR}/openssl.conf \
				${PKG_SYSCONFDIR}/yate/openssl.conf
CONF_FILES+=		${EGDIR}/pbxassist.conf \
				${PKG_SYSCONFDIR}/yate/pbxassist.conf
CONF_FILES+=		${EGDIR}/pgsqldb.conf \
				${PKG_SYSCONFDIR}/yate/pgsqldb.conf
CONF_FILES+=		${EGDIR}/presence.conf \
				${PKG_SYSCONFDIR}/yate/presence.conf
CONF_FILES+=		${EGDIR}/providers.conf \
				${PKG_SYSCONFDIR}/yate/providers.conf
CONF_FILES+=		${EGDIR}/queues.conf ${PKG_SYSCONFDIR}/yate/queues.conf
CONF_FILES+=		${EGDIR}/queuesnotify.conf \
				${PKG_SYSCONFDIR}/yate/queuesnotify.conf
CONF_FILES+=		${EGDIR}/regexroute.conf \
				${PKG_SYSCONFDIR}/yate/regexroute.conf
CONF_FILES+=		${EGDIR}/regfile.conf \
				${PKG_SYSCONFDIR}/yate/regfile.conf
CONF_FILES+=		${EGDIR}/register.conf \
				${PKG_SYSCONFDIR}/yate/register.conf
CONF_FILES+=		${EGDIR}/rmanager.conf \
				${PKG_SYSCONFDIR}/yate/rmanager.conf
CONF_FILES+=		${EGDIR}/sigtransport.conf \
				${PKG_SYSCONFDIR}/yate/sigtransport.conf
CONF_FILES+=		${EGDIR}/sip_cnam_lnp.conf \
				${PKG_SYSCONFDIR}/yate/sip_cnam_lnp.conf
CONF_FILES+=		${EGDIR}/sipfeatures.conf \
				${PKG_SYSCONFDIR}/yate/sipfeatures.conf
CONF_FILES+=		${EGDIR}/ss7_lnp_ansi.conf \
				${PKG_SYSCONFDIR}/yate/ss7_lnp_ansi.conf
CONF_FILES+=		${EGDIR}/subscription.conf \
				${PKG_SYSCONFDIR}/yate/subscription.conf
CONF_FILES+=		${EGDIR}/tdmcard.conf \
				${PKG_SYSCONFDIR}/yate/tdmcard.conf
CONF_FILES+=		${EGDIR}/tonegen.conf \
				${PKG_SYSCONFDIR}/yate/tonegen.conf
CONF_FILES+=		${EGDIR}/users.conf ${PKG_SYSCONFDIR}/yate/users.conf
CONF_FILES+=		${EGDIR}/wpcard.conf ${PKG_SYSCONFDIR}/yate/wpcard.conf
CONF_FILES+=		${EGDIR}/yate-qt4.conf \
				${PKG_SYSCONFDIR}/yate/yate-qt4.conf
CONF_FILES+=		${EGDIR}/yate.conf ${PKG_SYSCONFDIR}/yate/yate.conf
CONF_FILES+=		${EGDIR}/yiaxchan.conf \
				${PKG_SYSCONFDIR}/yate/yiaxchan.conf
CONF_FILES+=		${EGDIR}/yjinglechan.conf \
				${PKG_SYSCONFDIR}/yate/yjinglechan.conf
CONF_FILES+=		${EGDIR}/yradius.conf \
				${PKG_SYSCONFDIR}/yate/yradius.conf
CONF_FILES+=		${EGDIR}/yrtpchan.conf \
				${PKG_SYSCONFDIR}/yate/yrtpchan.conf
CONF_FILES+=		${EGDIR}/ysigchan.conf \
				${PKG_SYSCONFDIR}/yate/ysigchan.conf
CONF_FILES+=		${EGDIR}/ysipchan.conf \
				${PKG_SYSCONFDIR}/yate/ysipchan.conf
CONF_FILES+=		${EGDIR}/ysnmpagent.conf \
				${PKG_SYSCONFDIR}/yate/ysnmpagent.conf
CONF_FILES+=		${EGDIR}/ysockschan.conf \
				${PKG_SYSCONFDIR}/yate/ysockschan.conf
CONF_FILES+=		${EGDIR}/ystunchan.conf \
				${PKG_SYSCONFDIR}/yate/ystunchan.conf
CONF_FILES+=		${EGDIR}/zapcard.conf \
				${PKG_SYSCONFDIR}/yate/zapcard.conf
CONF_FILES+=		${EGDIR}/zlibcompress.conf \
				${PKG_SYSCONFDIR}/yate/zlibcompress.conf

SUBST_CLASSES+=		egdir
SUBST_FILES.egdir=	conf.d/Makefile
SUBST_MESSAGE.egdir=	Fixing EGDIR path.
SUBST_SED.egdir=	-e "s|etc/yate|${EGDIR}|1"
SUBST_STAGE.egdir=	pre-install
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}

SUBST_CLASSES+=		php
SUBST_FILES.php=	share/scripts/banbrutes.php share/scripts/leavemail.php
SUBST_FILES.php+=	share/scripts/queue_in.php share/scripts/queue_out.php
SUBST_FILES.php+=	share/scripts/route.php share/scripts/voicemail.php
SUBST_MESSAGE.php=	Fixing PHP interpreter path.
SUBST_SED.php=		-e "s|/usr/bin/php|${PREFIX}/bin/php|1"
SUBST_STAGE.php=	post-patch

# doxygen and kdoc for doc options
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
#.include "../../devel/pwlib/buildlink3.mk"
.include "../../comms/spandsp/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../wip/ilbc-rfc3951/buildlink3.mk"
#.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
