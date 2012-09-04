# $NetBSD: Makefile,v 1.2 2012/09/04 09:23:42 jihbed Exp $
#

DISTNAME=	maloc-1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.fetk.org/codes/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fetk.org/codes/maloc/
COMMENT=	Minimal Abstraction Layer for Object-oriented C
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/maloc

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c fortran
USE_GNU_READLINE=	yes

#CONFIGURE_ARGS+=	--enable-efence

.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mpi
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
