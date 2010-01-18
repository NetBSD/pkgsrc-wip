# $NetBSD: Makefile,v 1.6 2010/01/18 09:38:18 thomasklausner Exp $

DISTNAME=	callweaver-1.2.1
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://devs.callweaver.org/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	x400@msfu.ru
HOMEPAGE=	http://www.callweaver.org/
COMMENT=	The Callweaver Software PBX

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++ fortran
USE_TOOLS+=		gmake perl:run

USE_GNU_READLINE=	yes
USE_NCURSES=		yes

PKG_USERS= 		callweaver:callweaver
PKG_GROUPS=		callweaver

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	callweaver

CWPREFIX?=		${PREFIX}
CWEXECDIR?=		${PREFIX}/bin
CWUTILSDIR?=		${PREFIX}/sbin
CWCONFDIR?=		${PREFIX}/etc/callweaver
CWLIBDIR?=		${PREFIX}/lib/callweaver
CWVARDIR?=		${VARBASE}/db/callweaver
CWDATADIR?=		${PREFIX}/share/callweaver
CWLOGDIR?=		${VARBASE}/log/callweaver
CWRUNDIR?=		${VARBASE}/run
CWSPOOLDIR?=		${VARBASE}/spool/callweaver
CWMANDIR?=		${PREFIX}/man
CWDOCDIR?=		${PREFIX}/share/doc/callweaver

CWCONFEXAMPLESDIR?=	${PREFIX}/share/examples/callweaver

SUBST_CLASSES+=         callweaver
SUBST_STAGE.callweaver=	pre-configure
SUBST_FILES.callweaver=	layout.freebsd
SUBST_SED.callweaver+=	-e 's|^ *\(cwprefix\)=.*|\1=${CWPREFIX}|'
SUBST_SED.callweaver+=	-e 's|^ *\(cwexecdir\)=.*|\1=${CWEXECDIR}|'
SUBST_SED.callweaver+=  -e 's|^ *\(cwutilsdir\)=.*|\1=${CWUTILSDIR}|'
SUBST_SED.callweaver+=  -e 's|^ *\(cwconfdir\)=.*|\1=${CWCONFDIR}|'
SUBST_SED.callweaver+=  -e 's|^ *\(cwlibdir\)=.*|\1=${CWLIBDIR}|'
SUBST_SED.callweaver+=	-e 's|^ *\(cwvardir\)=.*|\1=${CWVARDIR}|'
SUBST_SED.callweaver+=  -e 's|^ *\(cwdatadir\)=.*|\1=${CWDATADIR}|'
SUBST_SED.callweaver+=	-e 's|^ *\(cwlogdir\)=.*|\1=${CWLOGDIR}|'
SUBST_SED.callweaver+=	-e 's|^ *\(cwrundir\)=.*|\1=${CWRUNDIR}|'
SUBST_SED.callweaver+=	-e 's|^ *\(cwspooldir\)=.*|\1=${CWSPOOLDIR}|'
SUBST_SED.callweaver+=  -e 's|^ *\(cwmandir\)=.*|\1=${CWMANDIR}|'
SUBST_SED.callweaver+=  -e 's|^ *\(cwdocdir\)=.*|\1=${CWDOCDIR}|'

CONFIGURE_ARGS+= 	--with-directory-layout=freebsd
CONFIGURE_ARGS+= 	--localstatedir=${VARBASE}
CONFIGURE_ARGS+= 	--with-app_backticks --with-app_dtmftotext --with-app_page --with-app_valetparking

.include "options.mk"

RCD_SCRIPTS=		callweaver

OWN_DIRS+=		${CWLOGDIR} ${CWSPOOLDIR} ${CWVARDIR}

.for f in adsi.conf \
	adtranvofr.conf \
	agents.conf \
	amd.conf \
	callweaver.adsi \
	callweaver.conf \
	cdr.conf \
	cdr_custom.conf \
	cdr_manager.conf \
	cdr_tds.conf \
	codecs.conf \
	db-memcached.conf \
	dnsmgr.conf \
	dundi.conf \
	enum.conf \
	extconfig.conf \
	extensions.ael \
	extensions.conf \
	features.conf \
	iax.conf \
	indications.conf \
	logger.conf \
	manager.conf \
	meetme.conf \
	mgcp.conf \
	modem.conf \
	modules.conf \
	musiconhold.conf \
	muted.conf \
	osp.conf \
	privacy.conf \
	queues.conf \
	res_snmp.conf \
	rtp.conf \
	sip.conf \
	sip_notify.conf \
	udptl.conf \
	voicemail.conf \
	woomera.conf
CONF_FILES+=		${CWCONFEXAMPLESDIR:Q}/${f} ${CWCONFDIR:Q}/${f}
.endfor

.if !empty(PKG_OPTIONS:Mjabber)
.for f in res_jabber.conf
CONF_FILES+=            ${CWCONFEXAMPLESDIR:Q}/${f} ${CWCONFDIR:Q}/${f}
.endfor
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.for f in cdr_mysql.conf \
	res_mysql.conf
CONF_FILES+=		${CWCONFEXAMPLESDIR:Q}/${f} ${CWCONFDIR:Q}/${f}
.endfor
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.for f in cdr_pgsql.conf \
	res_pgsql.conf
CONF_FILES+=		${CWCONFEXAMPLESDIR:Q}/${f} ${CWCONFDIR:Q}/${f}
.endfor
.endif

PKGCONFIG_OVERRIDE+=    sqlite3-embedded/sqlite3.pc.in
PKGCONFIG_OVERRIDE+=    sqlite3-embedded/sqlite.pc.in

.include "../../audio/speex/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/spandsp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
