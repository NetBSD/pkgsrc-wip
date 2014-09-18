# $NetBSD: Makefile,v 1.1 2014/09/18 00:43:30 makoto Exp $

PKGNAME=	gnuradio-atsc-${VERSION}
COMMENT=	Advanced Television Systems Committee, ATSC module of gnuradio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=    -DENABLE_GR_ATSC=ON
CMAKE_ARGS+=    -DENABLE_GR_FEC=ON

DEPENDS+=	gnuradio-fec-[0-9]*:../../wip/gnuradio-fec

PLIST_MINUS+=	fec
.include	"../../mk/bsd.pkg.mk"
