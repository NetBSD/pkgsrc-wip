# $NetBSD: Makefile,v 1.2 2015/09/17 13:48:05 makoto Exp $

PKGNAME=	gnuradio-ctrlport-${VERSION}
COMMENT=	New set of hooks into GNU Radio to allow a remote client to attach
.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True

.include	"../../mk/bsd.pkg.mk"
