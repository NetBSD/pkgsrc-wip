# $NetBSD: Makefile,v 1.7 2012/09/24 16:56:34 asau Exp $
#

DISTNAME=	nspostgres-4.0
PKGNAME=	aols-postgres-4.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=	iharding@destinydata.com
HOMEPAGE=	http://www.aolserver.com/
COMMENT=	Postgres database access module for aolserver


MAKE_FLAGS+=	POSTGRES=${PREFIX} INST=/${PREFIX}/include/nsd \
		TCL_CC=gcc
CFLAGS+=	-I/usr/pkg/include/nsd/include

USE_TOOLS+=	gmake

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
