# $NetBSD: Makefile,v 1.1.1.1 2004/06/01 16:40:26 ianharding Exp $
#

DISTNAME=		aolserver-4.01-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://www.aolserver.com/
COMMENT=		America Online's open source web server

MAKE_FLAGS=		NSHOME=${WRKSRC}
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
OWN_DIRS=		?
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
PTHREAD_OPTS+=  	require

EGDIR=                  ${PREFIX}/share/examples/nsd
PKG_SYSCONFSUBDIR=      nsd
NSD_LOGDIR=		/var/log/nsd
NSD_USER?=		nsadmin
NSD_GROUP?=		nsadmin

PKG_GROUPS=		${NSD_GROUP}
PKG_USERS=		${NSD_USER} ${NSD_GROUP}::AOLServer\\ User::${SH}

CONF_FILES=		${EGDIR}/nsd.tcl ${PKG_SYSCONFDIR}/nsd.tcl
RCD_SCRIPTS=		nsd

OWN_DIRS=		${NSD_LOGDIR}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
