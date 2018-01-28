# $NetBSD: Makefile,v 1.17 2012/09/24 16:56:34 asau Exp $
#

DISTNAME=		aolserver-4.0.10-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://www.aolserver.com/
COMMENT=		America Online's open source web server


MAKE_FLAGS+=		NSHOME=${WRKSRC}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PTHREAD_OPTS+=		require

NSD_LOGDIR=		${VARBASE}/log/nsd
NSD_PIDDIR=		${VARBASE}/run/nsd
NSD_USER?=		nsadmin
NSD_GROUP?=		nsadmin

PKG_GROUPS=		${NSD_GROUP}
PKG_USERS=		${NSD_USER}:${NSD_GROUP}::Aolserver\ User

EGDIR=			${PREFIX}/share/examples/nsd
CONF_FILES=		${EGDIR}/sample-config.tcl ${PKG_SYSCONFDIR}/nsd.tcl
RCD_SCRIPTS=		nsd

OWN_DIRS_PERMS=		${NSD_LOGDIR} ${NSD_USER} ${NSD_GROUP} 740
OWN_DIRS_PERMS+=	${NSD_PIDDIR} ${NSD_USER} ${NSD_GROUP} 740

SUBST_CLASSES+=		cl1
SUBST_STAGE.cl1=	post-patch
SUBST_FILES.cl1=	sample-config.tcl
SUBST_SED.cl1=		-e s!@PREFIX@!${PREFIX}!g \
			-e s!@VARBASE@!${VARBASE}!g

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
