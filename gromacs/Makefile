# $NetBSD: Makefile,v 1.12 2010/01/12 13:51:21 asau Exp $
#

DISTNAME=		gromacs-4.0.7
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=		pih@xbase.dk
HOMEPAGE=		http://www.gromacs.org/
COMMENT=		Molecular dynamics package

PKG_DESTDIR_SUPPORT=	user-destdir

# Official recommendation is not to use the gcc 4.1.x set of compilers.

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-double --program-suffix=
CONFIGURE_ARGS+=	--with-gsl

.include "options.mk"

#TEST_TARGET=		tests	# something extra needed?

CHECK_PORTABILITY_SKIP=	configure

REPLACE_PERL=		scripts/demux.pl scripts/xplor2gmx.pl

.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"	# optional
.include "../../textproc/libxml2/buildlink3.mk"	# optional
.include "../../mk/bsd.pkg.mk"
