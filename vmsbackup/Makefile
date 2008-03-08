# $NetBSD: Makefile,v 1.8 2008/03/08 11:30:44 hoka_adam Exp $
#

DISTNAME=		vmsbackup
PKGNAME=		vmsbackup-3.0
CATEGORIES=		archivers
MASTER_SITES=		http://garbo.uwasa.fi/pub/unix/vmsbackup/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://garbo.uwasa.fi/pub/unix/vmsbackup/
COMMENT=		Utility to read VMS backup tapes

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		vmsbackup
MAKE_FLAGS+=		PREFIX=${PREFIX:Q}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	SWAP=-DSWAP
.endif

.include "../../mk/bsd.pkg.mk"
