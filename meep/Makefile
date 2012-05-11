# $NetBSD: Makefile,v 1.7 2012/05/11 20:05:59 outpaddling Exp $
#

DISTNAME=	meep-1.1.1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/meep/
COMMENT=	FDTD simulation software to model electromagnetic systems
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	bash-[0-9]*:../../shells/bash

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=--with-libctl=${PREFIX}/share/libctl

DEPENDS+=	bash:../../shells/bash

.include "../../wip/mpb/buildlink3.mk"
#.include "../../math/blas/buildlink3.mk"
#.include "../../math/lapack/buildlink3.mk"
#.include "../../devel/hdf5/buildlink3.mk"
#.include "../../math/fftw2/buildlink3.mk"
#.include "../../devel/readline/buildlink3.mk"
#.include "../../wip/libctl/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/harminv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
