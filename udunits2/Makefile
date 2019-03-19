# $NetBSD$

DISTNAME=	udunits-2.2.26
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/udunits/

MAINTAINER=	bacon@NetBSD.org
COMMENT=	Library for manipulating units of physical quantities
LICENSE=	modified-bsd

# MAKE_JOBS_SAFE=	no

USE_LIBTOOL=		yes
# USE_TOOLS=		gmake
GNU_CONFIGURE=		yes
INFO_FILES=		yes

# CONFIGURE_ARGS+=	--disable-shared
# CONFIGURE_ENV+=		ac_cv_header_CUnit_CUnit_h=no

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
