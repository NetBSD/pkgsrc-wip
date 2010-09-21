# $NetBSD: Makefile,v 1.3 2010/09/21 20:43:41 crocusino Exp $
#

DISTNAME=	octave-3.2.4
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.octave.org/pub/octave/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://www.octave.org/
COMMENT=	The famous MATLAB-like GNU software

LICENSE=	gnu-gpl-v3 # LICENSE is GPL but not clear which version

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	bison:../../devel/bison
DEPENDS+=	gnuplot:../../graphics/gnuplot

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake gsed pkg-config perl makeinfo
USE_GNU_READLINE=	yes
USE_LANGUAGES=	c c++ fortran77 # use "fortran" instead of "fortran77" for 2010Q2 and older branches
INFO_FILES=yes

CONFIGURE_ARGS+=	--disable-freetypetest --enable-static --disable-shared --disable-dl --without-framework-carbon --without-zlib --without-hdf5 --without-fftw --without-glpk --without-framework-opengl --without-qrupdate --without-amd --without-umfpack --without-colamd --without-ccolamd --without-cholmod --without-cxsparse --without-cxsparse --without-arpack --without-curl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
