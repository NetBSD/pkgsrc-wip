# $NetBSD: Makefile,v 1.3 2012/10/03 15:09:50 asau Exp $
#

DISTNAME=	maloc-1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.fetk.org/codes/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fetk.org/codes/maloc/
COMMENT=	Minimal Abstraction Layer for Object-oriented C
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/maloc

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c fortran
USE_GNU_READLINE=	yes

#CONFIGURE_ARGS+=	--enable-efence

.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mpi
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
