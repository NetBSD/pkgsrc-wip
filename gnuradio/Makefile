# $NetBSD: Makefile,v 1.6 2014/10/07 06:05:21 makoto Exp $

META_PACKAGE=	yes

.include	"../../wip/gnuradio-core/version.mk"

DISTNAME=	gnuradio-${VERSION}
CATEGORIES=	meta-pkgs ham
MASTER_SITES=	# empty
DISTFILES=	# empty
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gnuradio/
COMMENT=	Collection of GNU Radio (meta package, easy to install whole thing)

# 16 packages for now ( -default is NOT included )
DEPENDS+=	gnuradio-channels-[0-9]*:../../wip/gnuradio-channels
DEPENDS+=	gnuradio-companion-[0-9]*:../../wip/gnuradio-companion
DEPENDS+=	gnuradio-core-[0-9]*:../../wip/gnuradio-core
DEPENDS+=	gnuradio-ctrlport-[0-9]*:../../wip/gnuradio-ctrlport
DEPENDS+=	gnuradio-digital-[0-9]*:../../wip/gnuradio-digital
DEPENDS+=	gnuradio-doxygen-[0-9]*:../../wip/gnuradio-doxygen
DEPENDS+=	gnuradio-dtv-[0-9]*:../../wip/gnuradio-dtv
DEPENDS+=	gnuradio-fec-[0-9]*:../../wip/gnuradio-fec
DEPENDS+=	gnuradio-qtgui-[0-9]*:../../wip/gnuradio-qtgui
DEPENDS+=	gnuradio-trellis-[0-9]*:../../wip/gnuradio-trellis
DEPENDS+=	gnuradio-uhd-[0-9]*:../../wip/gnuradio-uhd
DEPENDS+=	gnuradio-utils-[0-9]*:../../wip/gnuradio-utils
DEPENDS+=	gnuradio-video-sdl-[0-9]*:../../wip/gnuradio-video-sdl
DEPENDS+=	gnuradio-vocoder-[0-9]*:../../wip/gnuradio-vocoder
DEPENDS+=	gnuradio-wavelet-[0-9]*:../../wip/gnuradio-wavelet
DEPENDS+=	gnuradio-zeromq-[0-9]*:../../wip/gnuradio-zeromq

.include "../../mk/bsd.pkg.mk"
