# $NetBSD: Makefile,v 1.6 2011/11/04 22:58:46 cheusov Exp $
#

DISTNAME=	octave-3.4.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gnu.org/gnu/octave/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://www.octave.org/
COMMENT=	The famous MATLAB-like GNU software

LICENSE=	gnu-gpl-v3 # LICENSE is GPL but not clear which version

BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot

PKG_DESTDIR_SUPPORT=	user-destdir

USE_GNU_READLINE=	yes
USE_TOOLS+=	autoconf gmake gsed pkg-config perl makeinfo bison
GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c++ fortran77

CONFIGURE_ARGS+=	--enable-dl
CONFIGURE_ARGS+=	--disable-static
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--without-glpk
CONFIGURE_ARGS+=	--without-hdf5
CONFIGURE_ARGS+=	--without-qhull

INFO_FILES=yes

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
