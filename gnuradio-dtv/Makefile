# $NetBSD: Makefile,v 1.1 2014/09/18 00:43:31 makoto Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
COMMENT=	Implementing various digital television standards of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DTV=True

.include	"../../wip/gnuradio-fec/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
