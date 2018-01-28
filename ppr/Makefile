# $NetBSD: Makefile,v 1.13 2014/09/08 21:24:08 thomasklausner Exp $

DISTNAME=		ppr-1.53
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ppr/}\
			ftp://ppr-dist.trincoll.edu/pub/ppr/

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://ppr.trincoll.edu/
COMMENT=		PPR is a print spooler for PostScript printers

CONFLICTS+=		LPRng-[0-9]* LPRng-core-[0-9]* cups-[0-9]*


USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure

EGDIR=			${PREFIX}/share/examples
PKG_SYSCONFSUBDIR=	ppr
PPR_CONFDIR=		${PKG_SYSCONFDIR}

CONFIGURE_ARGS+=	--prefix=${PREFIX}

# Use the EGDIR here?
#CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}

CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--spooldir=${VARBASE}/spool
CONFIGURE_ARGS+=	--x11bindir=${X11BASE}/bin
CONFIGURE_ARGS+=	--user-ppr=${PPR_USER:Q}
CONFIGURE_ARGS+=	--user-pprwww=${PPRWEB_USER:Q}
CONFIGURE_ARGS+=	--group-ppr=${PPR_GROUP:Q}
CONFIGURE_ARGS+=	--with-gettext
CONFIGURE_ARGS+=	--with-tdb
CONFIGURE_ARGS+=	--with-gdbm

.include "../../mk/bsd.prefs.mk"

PPR_USER?=		ppr
PPRWEB_USER?=		pprwww
PPR_GROUP?=		ppr

PKG_GROUPS=		${PPR_GROUP}
PKG_USERS=		${PPR_USER}:${PPR_GROUP}::PPR\ user::${SH}
PKG_USERS+=		${PPRWEB_USER}:${PPR_GROUP}::PPR\ web\ user::${SH}

#FILES_SUBST+=		PPR_USER=${PPR_USER}
#FILES_SUBST+=		PPRWEB_USER=${PPRWEB_USER}
#FILES_SUBST+=		PPR_GROUP=${PPR_GROUP}

BUILD_DEFS+=		PPR_USER PPRWEB_USER PPR_GROUP

SPECIAL_PERMS=		${PREFIX}/bin/lppasswd ${PPR_USER} ${PPR_GROUP} 4755
CONF_FILES=		${EGDIR}/ppr.conf ${PKG_SYSCONFDIR}/ppr.conf
CONF_FILES+=		${EGDIR}/lprsrv.conf ${PKG_SYSCONFDIR}/lprsrv.conf
CONF_FILES+=		${EGDIR}/uprint-remote.conf ${PKG_SYSCONFDIR}/uprint_remote.conf
CONF_FILES+=		${EGDIR}/uprint.conf ${PKG_SYSCONFDIR}/uprint.conf
CONF_FILES+=		${EGDIR}/acl/ppad.allow ${PKG_SYSCONFDIR}/acl/ppad.allow
CONF_FILES+=		${EGDIR}/acl/ppad.allow ${PKG_SYSCONFDIR}/acl/ppad.allow
CONF_FILES+=		${EGDIR}/acl/ppop.allow ${PKG_SYSCONFDIR}/acl/ppop.allow
CONF_FILES+=		${EGDIR}/acl/pprprox.allow ${PKG_SYSCONFDIR}/acl/pprprox.allow
CONF_FILES+=		${EGDIR}/acl/ppuser.allow ${PKG_SYSCONFDIR}/acl/ppuser.allow
SUPPORT_FILES=		${EGDIR}/media.db ${PKG_SYSCONFDIR}/media.db

RCD_SCRIPTS=			pprd ppr-papd papsrv lprsrv
RCD_SCRIPT_SRC.pprd=		# empty
RCD_SCRIPT_SRC.ppr-papd=	# empty
RCD_SCRIPT_SRC.papsrv=		# empty
RCD_SCRIPT_SRC.lprsrv=		# empty

OWN_DIRS=		${PKG_SYSCONFDIR}/acl
OWN_DIRS+=		${PKG_SYSCONFDIR}/aliases
OWN_DIRS+=		${PKG_SYSCONFDIR}/groups
OWN_DIRS+=		${PKG_SYSCONFDIR}/mounted
OWN_DIRS+=		${PKG_SYSCONFDIR}/printers
OWN_DIRS+=		${VARBASE}/spool/ppr

.include "options.mk"

.include "../../wip/natali/buildlink3.mk"
.include "../../net/netatalk22/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
