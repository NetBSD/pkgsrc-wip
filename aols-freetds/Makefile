# $NetBSD: Makefile,v 1.1.1.1 2004/10/12 15:02:05 ianharding Exp $
#

DISTNAME=		nsfreetds-0.4-src
PKGNAME=                ${DISTNAME:S/-src//}
CATEGORIES=             www
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		www.aolserver.com
COMMENT=		FreeTDS database access module for aolserver

WRKSRC=                 ${WRKDIR}/${PKGNAME}

MAKE_FLAGS+=		NSHOME=/${PREFIX}/include/nsd \
			TCL_CC=gcc
CFLAGS+=		-I/usr/pkg/include/nsd/include

USE_BUILDLINK3=         yes
USE_GNU_TOOLS+=         make

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
