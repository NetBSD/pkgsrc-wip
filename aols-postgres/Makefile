# $NetBSD: Makefile,v 1.3 2005/04/11 21:09:44 tvierling Exp $
#

DISTNAME=	nspostgres-4.0
PKGNAME=	aols-postgres-4.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=	iharding@destinydata.com
HOMEPAGE=	www.aolserver.com
COMMENT=	Postgres database access module for aolserver

MAKE_FLAGS+=	POSTGRES=${PREFIX} INST=/${PREFIX}/include/nsd \
		TCL_CC=gcc
CFLAGS+=	-I/usr/pkg/include/nsd/include

USE_GNU_TOOLS+=         make

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
