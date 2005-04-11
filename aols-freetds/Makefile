# $NetBSD: Makefile,v 1.3 2005/04/11 21:09:43 tvierling Exp $
#

DISTNAME=		nsfreetds-0.4-src
PKGNAME=                aols-freetds-0.4
CATEGORIES=             www
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		www.aolserver.com
COMMENT=		FreeTDS database access module for aolserver

WRKSRC=                 ${WRKDIR}/${DISTNAME:S/-src//}

MAKE_FLAGS+=		NSHOME=/${PREFIX}/include/nsd \
			TCL_CC=gcc
CFLAGS+=		-I/usr/pkg/include/nsd/include

USE_GNU_TOOLS+=         make

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
