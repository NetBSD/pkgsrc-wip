# $NetBSD$

DISTNAME=	wcslib-7.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.atnf.csiro.au/pub/software/wcslib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://www.atnf.csiro.au/people/mcalabre/WCS/
COMMENT=	FITS World Coordinate Systems library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c fortran
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

# We could use pgplot, but it is not legally
# mirror-able and also really, really old.
CONFIGURE_ARGS+=	--without-pgplot

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
