# $NetBSD: Makefile,v 1.2 2005/11/02 18:00:22 thomasklausner Exp $
#

PKGNAME=		mppenc-1.15
DISTNAME=		mpcsv7-src-1.15v
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.musepack.net/
COMMENT=		Mpeg-Plus encoder/decoder

WRKSRC=		${WRKDIR}/sv7
USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mppenc ${PREFIX}/bin

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
