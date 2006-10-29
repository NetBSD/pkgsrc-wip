# $NetBSD: Makefile,v 1.4 2006/10/29 11:23:10 shattered Exp $
#

DISTNAME=		mpcsv7-src-1.15v
PKGNAME=		mppenc-1.15
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
