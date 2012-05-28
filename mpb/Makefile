# $NetBSD: Makefile,v 1.6 2012/05/28 15:40:58 outpaddling Exp $
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
USE_LANGUAGES=	c fortran77
USE_TOOLS+=	gsed

CONFIGURE_ARGS+=--with-libctl=${PREFIX}/share/libctl
CFLAGS+=	-DH5_USE_16_API=1

# Prepend ${DESTDIR} to $(prefix), but only in install commands.
# It happens that these instances are preceded by a space, and those
# we don't want to change are not.
SUBST_CLASSES+=	install-prefix
SUBST_FILES.install-prefix=	mpb-ctl/Makefile utils/Makefile
SUBST_STAGE.install-prefix=	post-configure
SUBST_MESSAGE.install-prefix=	Patching install prefix.
SUBST_SED.install-prefix=	-e 's| $$(prefix)| ${DESTDIR}$$(prefix)|g' \
				-e 's| $$(mandir)| ${DESTDIR}$$(mandir)|g'

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../wip/libctl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
