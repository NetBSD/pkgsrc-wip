# $NetBSD: Makefile,v 1.1.1.1 2003/04/20 15:14:16 cjep Exp $
#

DISTNAME=	vmsbackup
PKGNAME=	vmsbackup-3.0
CATEGORIES=	archivers
MASTER_SITES=	http://garbo.uwasa.fi/pub/unix/vmsbackup/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://garbo.uwasa.fi/pub/unix/vmsbackup/
COMMENT=	Utility to read VMS backup tapes

USE_BUILDLINK2=	YES
ALL_TARGET=	vmsbackup
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	SWAP=-DSWAP
.endif

.include "../../mk/bsd.pkg.mk"
