# $NetBSD: Makefile,v 1.4 2012/11/13 19:33:45 othyro Exp $
#

DISTNAME=	maloc-1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.fetk.org/codes/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fetk.org/codes/maloc/
COMMENT=	Minimal Abstraction Layer for Object-oriented C
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/maloc

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c fortran
USE_GNU_READLINE=	yes
USE_LIBTOOL=		yes

#CONFIGURE_ARGS+=	--enable-efence

.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mpi
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
