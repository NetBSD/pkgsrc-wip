# $NetBSD: Makefile,v 1.3 2004/07/20 18:15:55 ianharding Exp $
#

DISTNAME=		aolserver-4.0.7-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://www.aolserver.com/
COMMENT=		America Online's open source web server

MAKE_FLAGS=		NSHOME=${WRKSRC} TCL_CC="gcc -nostartfiles"
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
PTHREAD_OPTS+=  	require

NSD_LOGDIR=		${VARBASE}/log/nsd
NSD_PIDDIR=		${VARBASE}/run/nsd
NSD_USER?=		nsadmin
NSD_GROUP?=		nsadmin

PKG_GROUPS=		${NSD_GROUP}
PKG_USERS=		${NSD_USER} ${NSD_GROUP}

EGDIR=                  ${PREFIX}/share/examples/nsd
CONF_FILES=		${EGDIR}/sample-config.tcl ${PKG_SYSCONFDIR}/nsd.tcl
RCD_SCRIPTS=		nsd

OWN_DIRS_PERMS=		${NSD_LOGDIR} ${NSD_USER} ${NSD_GROUP} 740
OWN_DIRS_PERMS+=	${NSD_PIDDIR} ${NSD_USER} ${NSD_GROUP} 740

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
