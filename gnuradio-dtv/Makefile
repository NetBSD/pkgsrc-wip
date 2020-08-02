# $NetBSD: Makefile,v 1.19 2019/08/22 12:23:22 ryoon Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
COMMENT=	Various digital television standards of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DTV=True
CMAKE_ARGS+=	-DENABLE_GR_FEC=True

PLIST_MINUS+=	fec
.include	"../../wip/gnuradio-fec/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
