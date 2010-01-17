# $NetBSD: Makefile,v 1.8 2010/01/17 12:03:22 thomasklausner Exp $
#

DISTNAME=		nsfreetds-0.4-src
PKGNAME=		aols-freetds-0.4
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://www.aolserver.com/
COMMENT=		FreeTDS database access module for aolserver

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}

MAKE_FLAGS+=		NSHOME=/${PREFIX}/include/nsd \
			TCL_CC=gcc
CFLAGS+=		-I/usr/pkg/include/nsd/include

USE_TOOLS+=		gmake

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
