# $NetBSD: Makefile,v 1.1.1.1 2007/07/14 11:49:07 yeled Exp $

DISTNAME=		symon-2.76
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.xs4all.nl/~wpd/symon/philes/

MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://www.xs4all.nl/~wpd/symon/
COMMENT=		system monitor suite

WRKSRC?=        ${WRKDIR}/symon
#MAKE_ARGS+=	RRDDIR=${PREFIX}

#RCD_SCRIPTS=		symon symux
SYMON_USER?=       	_symon
PKG_HOME.symon?=	${VARBASE}/empty
SYMON_GROUP?=      	symon
PKG_GROUPS?=		${SYMON_GROUP}
PKG_USERS?=		${SYMON_USER}:${SYMON_GROUP}::symon\ Account

MAKE_DIRS_PERMS+=         ${VARBASE}/var/empty ${ROOT_USER} ${ROOT_GROUP} 0700

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
