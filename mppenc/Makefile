# $NetBSD: Makefile,v 1.3 2006/08/25 21:29:36 dhowland Exp $
#

PKGNAME=		mppenc-1.15
DISTNAME=		mpcsv7-src-1.15v
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.musepack.net/
COMMENT=		Mpeg-Plus encoder/decoder

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

WRKSRC=		${WRKDIR}/sv7
USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mppenc ${PREFIX}/bin

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
