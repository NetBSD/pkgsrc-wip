# $NetBSD: Makefile,v 1.2 2014/09/28 00:40:28 makoto Exp $

PKGNAME=	gnuradio-fcd-${VERSION}
COMMENT=	FanCube support of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_FCD=True

.include	"../../devel/orc/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"
.include	"../../wip/py-wxWidgets/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
