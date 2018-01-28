# $NetBSD: Makefile,v 1.12 2012/09/24 16:56:34 asau Exp $
#

DISTNAME=		aolserver-4.01-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://www.aolserver.com/
COMMENT=		America Online's open source web server


MAKE_FLAGS+=		NSHOME=${WRKSRC}
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
OWN_DIRS=		?
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/nsd
PKG_SYSCONFSUBDIR=	nsd
NSD_LOGDIR=		/var/log/nsd
NSD_ROOT=		${PREFIX}/share/nsd
NSD_USER?=		nsadmin
NSD_GROUP?=		nsadmin

PKG_GROUPS=		${NSD_GROUP}
PKG_USERS=		${NSD_USER} ${NSD_GROUP}::AOLServer\ User::${SH}

CONF_FILES=		${EGDIR}/nsd.tcl ${PKG_SYSCONFDIR}/nsd.tcl
RCD_SCRIPTS=		nsd

OWN_DIRS=		${NSD_LOGDIR}
OWN_DIRS+=		${NSD_ROOT}
OWN_DIRS+=		${NSD_ROOT}/modules
OWN_DIRS+=		${NSD_ROOT}/modules/tcl
OWN_DIRS+=		${NSD_ROOT}/servers
OWN_DIRS+=		${NSD_ROOT}/servers/server1
OWN_DIRS+=		${NSD_ROOT}/servers/server1/modules
OWN_DIRS+=		${NSD_ROOT}/servers/server1/pages

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
