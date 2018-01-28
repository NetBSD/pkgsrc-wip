# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:52 othyro Exp $
#

DISTNAME=	xmds-1.6.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmds/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://xmds.sourceforge.net/
COMMENT=	XMDS is a code generator that integrates equations
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	NO

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
