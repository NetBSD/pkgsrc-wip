# $NetBSD: Makefile,v 1.5 2005/04/11 21:16:11 tvierling Exp $
#

DISTNAME=	vmsbackup
PKGNAME=	vmsbackup-3.0
CATEGORIES=	archivers
MASTER_SITES=	http://garbo.uwasa.fi/pub/unix/vmsbackup/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://garbo.uwasa.fi/pub/unix/vmsbackup/
COMMENT=	Utility to read VMS backup tapes

BUILD_TARGET=	vmsbackup
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	SWAP=-DSWAP
.endif

.include "../../mk/bsd.pkg.mk"
