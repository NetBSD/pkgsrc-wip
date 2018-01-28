# $NetBSD: Makefile,v 1.12 2012/09/24 16:56:34 asau Exp $
#

DISTNAME=		nsopenssl-3.0b23-src
PKGNAME=		aols-openssl-3.0b23
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		http://aolserver.sourceforge.net/
COMMENT=		OpenSSL module for aolserver


WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}

MAKE_FLAGS+=		INST=/${PREFIX}/include/nsd \
			OPENSSL=${PREFIX} \
			TCL_CC=gcc
CFLAGS+=		-I/usr/pkg/include/nsd/include

USE_TOOLS+=		gmake

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
