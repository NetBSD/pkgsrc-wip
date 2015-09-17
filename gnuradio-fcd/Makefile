# $NetBSD: Makefile,v 1.6 2015/09/17 13:48:06 makoto Exp $

PKGNAME=	gnuradio-fcd-${VERSION}
COMMENT=	FanCube support of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_FCD=True

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
