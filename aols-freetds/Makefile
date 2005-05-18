# $NetBSD: Makefile,v 1.4 2005/05/18 09:26:57 rillig Exp $
#

DISTNAME=		nsfreetds-0.4-src
PKGNAME=                aols-freetds-0.4
CATEGORIES=             www
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://www.aolserver.com/
COMMENT=		FreeTDS database access module for aolserver

WRKSRC=                 ${WRKDIR}/${DISTNAME:S/-src//}

MAKE_FLAGS+=		NSHOME=/${PREFIX}/include/nsd \
			TCL_CC=gcc
CFLAGS+=		-I/usr/pkg/include/nsd/include

USE_GNU_TOOLS+=         make

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
