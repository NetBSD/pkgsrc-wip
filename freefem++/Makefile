# $NetBSD: Makefile,v 1.2 2012/12/15 08:27:24 asau Exp $
#

DISTNAME=	freefem++-3.19-1
CATEGORIES=	math
MASTER_SITES=	http://www.freefem.org/ff++/ftp/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.freefem.org/ff++/
COMMENT=	PDE oriented language using Finite Element Method
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison perl
USE_LANGUAGES=	c c++ fortran

### MACRO-CONFIGURATION : SANS DETAILS ###

### OpenGL
.include "../../graphics/MesaLib/buildlink3.mk"

###  parallel //
.include "../../mk/mpi.buildlink3.mk"

### Maths
.include "../../mk/blas.buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"

### libX11
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"

### x11/fltk
.include "../../x11/fltk/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
