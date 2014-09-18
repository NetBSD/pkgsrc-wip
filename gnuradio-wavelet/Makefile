# $NetBSD: Makefile,v 1.1 2014/09/18 00:43:32 makoto Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
COMMENT=	Implementing various digital television standards of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../mk/bsd.pkg.mk"
