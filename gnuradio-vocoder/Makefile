# $NetBSD: Makefile,v 1.16 2019/08/22 12:23:23 ryoon Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
COMMENT=	All available vocoders in GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
