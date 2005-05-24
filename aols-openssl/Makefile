# $NetBSD: Makefile,v 1.5 2005/05/24 10:29:22 rillig Exp $
#

DISTNAME=		nsopenssl-3.0b23-src
PKGNAME=                aols-openssl-3.0b23
CATEGORIES=             www
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://www.scottg.net/
COMMENT=		OpenSSL module for aolserver

WRKSRC=                 ${WRKDIR}/${DISTNAME:S/-src//}

MAKE_FLAGS+=		INST=/${PREFIX}/include/nsd \
			OPENSSL=${PREFIX} \
			TCL_CC=gcc
CFLAGS+=		-I/usr/pkg/include/nsd/include

USE_TOOLS+=         gmake

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
