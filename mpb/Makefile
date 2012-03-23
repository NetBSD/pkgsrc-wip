# $NetBSD: Makefile,v 1.2 2012/03/23 12:54:35 outpaddling Exp $
#

DISTNAME=	mpb-1.4.2
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/mpb/
COMMENT=	MIT Photonic Bands
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c fortran
USE_TOOLS+=	gsed

CONFIGURE_ARGS+=--with-libctl=${PREFIX}/share/libctl

# Does not want to install to destdir for reasons I haven't identified yet.
# If you know of a better fix than this hack, please drop me an email.
# I've tried configuring with --prefix=${DESTDIR}${PREFIX}, but my override
# gets overridden by pkgsrc.  Also tried some vars like INSTALL_MAKE_FLAGS,
# INSTALL_ROOT, PREFIX.
post-configure:
	gsed -i'' -e 's|$$(prefix)|${DESTDIR}$$(prefix)|' \
		  -e 's|$$(mandir)|${DESTDIR}$$(mandir)|' \
		${WRKSRC}/mpb-ctl/Makefile
	gsed -i'' -e 's|$$(prefix)|${DESTDIR}$$(prefix)|' \
		  -e 's|$$(mandir)|${DESTDIR}$$(mandir)|' \
		${WRKSRC}/utils/Makefile

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../wip/libctl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
