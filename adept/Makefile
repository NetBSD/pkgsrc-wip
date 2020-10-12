# $NetBSD$

DISTNAME=	adept-2.0.5
CATEGORIES=	math
MASTER_SITES=	http://www.met.reading.ac.uk/clouds/adept/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.met.reading.ac.uk/clouds/adept/
COMMENT=	Combined automatic differentiation and array library for C++
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt
USE_LANGUAGES=	c c++ fortran

.include "../../mk/blas.buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
