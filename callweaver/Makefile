# $NetBSD: Makefile,v 1.1.1.1 2008/12/05 15:39:43 x400 Exp $

DISTNAME=	callweaver-1.2.0.1
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

SUBST_CLASSES+=         callweaver
SUBST_STAGE.callweaver=	pre-configure
SUBST_FILES.callweaver=	layout.bsd
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

CONFIGURE_ARGS+= 	--with-directory-layout=bsd
CONFIGURE_ARGS+= 	--localstatedir=${VARBASE}
CONFIGURE_ARGS+= 	--with-app_backticks --with-app_dtmftotext --with-app_page --with-app_valetparking

.include "options.mk"

RCD_SCRIPTS=		callweaver

OWN_DIRS+=		${CWLOGDIR} ${CWSPOOLDIR} ${CWVARDIR}

CONF_FILES=
CONF_FILES+=		${CWCONFDIR}/adsi.conf \
			${CWCONFDIR}/adtranvofr.conf \
			${CWCONFDIR}/agents.conf \
			${CWCONFDIR}/callweaver.adsi \
			${CWCONFDIR}/callweaver.conf \
			${CWCONFDIR}/cdr.conf \
			${CWCONFDIR}/cdr_custom.conf \
			${CWCONFDIR}/cdr_manager.conf \
			${CWCONFDIR}/cdr_tds.conf \
			${CWCONFDIR}/codecs.conf \
			${CWCONFDIR}/db-memcached.conf \
			${CWCONFDIR}/dnsmgr.conf \
			${CWCONFDIR}/dundi.conf \
			${CWCONFDIR}/enum.conf \
			${CWCONFDIR}/extconfig.conf \
			${CWCONFDIR}/extensions.ael \
			${CWCONFDIR}/extensions.conf \
			${CWCONFDIR}/features.conf \
			${CWCONFDIR}/iax.conf \
			${CWCONFDIR}/indications.conf \
			${CWCONFDIR}/logger.conf \
			${CWCONFDIR}/manager.conf \
			${CWCONFDIR}/meetme.conf \
			${CWCONFDIR}/mgcp.conf \
			${CWCONFDIR}/modem.conf \
			${CWCONFDIR}/modules.conf \
			${CWCONFDIR}/musiconhold.conf \
			${CWCONFDIR}/muted.conf \
			${CWCONFDIR}/osp.conf \
			${CWCONFDIR}/privacy.conf \
			${CWCONFDIR}/queues.conf \
			${CWCONFDIR}/res_snmp.conf \
			${CWCONFDIR}/rtp.conf \
			${CWCONFDIR}/sip.conf \
			${CWCONFDIR}/sip_notify.conf \
			${CWCONFDIR}/udptl.conf \
			${CWCONFDIR}/voicemail.conf \
			${CWCONFDIR}/woomera.conf

PKGCONFIG_OVERRIDE+=    sqlite3-embedded/sqlite3.pc.in
PKGCONFIG_OVERRIDE+=    sqlite3-embedded/sqlite.pc.in

.include "../../audio/speex/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/spandsp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
