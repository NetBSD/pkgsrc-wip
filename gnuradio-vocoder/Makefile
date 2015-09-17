# $NetBSD: Makefile,v 1.3 2015/09/17 13:48:06 makoto Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
COMMENT=	All available vocoders in GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
