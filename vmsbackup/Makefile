# $NetBSD: Makefile,v 1.2 2003/08/29 10:31:26 thomasklausner Exp $
#

DISTNAME=	vmsbackup
PKGNAME=	vmsbackup-3.0
CATEGORIES=	archivers
MASTER_SITES=	http://garbo.uwasa.fi/pub/unix/vmsbackup/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
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
