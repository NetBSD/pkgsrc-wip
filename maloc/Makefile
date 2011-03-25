# $NetBSD: Makefile,v 1.1.1.1 2011/03/25 18:11:59 jihbed Exp $
#

DISTNAME=	maloc-1.4
CATEGORIES=	devel
MASTER_SITES=	http://www.fetk.org/codes/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fetk.org/codes/maloc/
COMMENT=	Minimal Abstraction Layer for Object-oriented C
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/maloc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison
USE_GNU_READLINE=	yes
USE_LANGUAGES=	c fortran

CONFIGURE_ARGS+=	--enable-mpi
#CONFIGURE_ARGS+=	--enable-efence

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
