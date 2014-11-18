# $NetBSD: Makefile,v 1.3 2014/11/18 05:27:27 makoto Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
COMMENT=	Various digital television standards of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DTV=True
CMAKE_ARGS+=	-DENABLE_GR_FEC=True

.include	"../../wip/gnuradio-fec/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
