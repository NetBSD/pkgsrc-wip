# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:10 asau Exp $
#

DISTNAME=	xmds-1.6.6
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/xmds/xmds/xmds-1.6.6/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://xmds.sourceforge.net/
COMMENT=	XMDS is a code generator that integrates equations
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=NO

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-fftw3=${BUILDLINK_PREFIX.fftw3}
CONFIGURE_ARGS+=	--enable-mpi
CONFIGURE_ARGS+=	--enable-threads

.include "../../math/fftw/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
