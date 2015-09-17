# $NetBSD: Makefile,v 1.3 2015/09/17 13:48:06 makoto Exp $

PKGNAME=	gnuradio-pager-${VERSION}
COMMENT=	FLEX radiopager receiver/demodulator of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_PAGER=ON

.include	"../../mk/bsd.pkg.mk"

# --   Dependency Boost_FOUND = 1
# --   Dependency ENABLE_GNURADIO_RUNTIME = ON
# --   Dependency ENABLE_GR_FILTER = ON
# --   Dependency ENABLE_GR_ANALOG = ON
# --   Enabling gr-pager support.
# --   Override with -DENABLE_GR_PAGER=ON/OFF
