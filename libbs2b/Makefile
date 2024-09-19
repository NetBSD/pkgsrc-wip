# $NetBSD: Makefile,v 1.1 2013/03/09 15:24:49 othyro Exp $
#

DISTNAME=	libbs2b-3.1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bs2b/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bs2b.sourceforge.net/
COMMENT=	Bauer stereophonic-to-binaural DSP
LICENSE=	mit

WRKSRC=		${WRKDIR}/libbs2b-3.1.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gsed pkg-config
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	libbs2b.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
