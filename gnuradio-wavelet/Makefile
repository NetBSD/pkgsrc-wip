# $NetBSD: Makefile,v 1.2 2014/09/28 00:40:28 makoto Exp $

PKGNAME=	gnuradio-wavelet-${VERSION}
COMMENT=	Implementing various digital television standards of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True

.include	"../../math/gsl/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
