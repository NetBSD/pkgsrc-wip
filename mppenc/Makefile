# $NetBSD: Makefile,v 1.1.1.1 2005/08/13 16:36:45 poppnk Exp $
#

PKGNAME=		mppenc-1.15
DISTNAME=		mpcsv7-src-1.15v
CATEGORIES=		wip audio
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
