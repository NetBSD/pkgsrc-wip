# $NetBSD: Makefile,v 1.4 2006/08/12 22:13:08 thomasklausner Exp $
DISTNAME=	lush-1.1
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lush/}
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	dauphin@enst.fr
HOMEPAGE=	http://lush.sourceforge.net/
COMMENT=	Lisp interpreter/compiler with a seamless interface to C

#PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

#CONFIGURE_ENV+=
CONFIGURE_ARGS+=	--without-bfd

#./configure --without-bfd

post-install:
	${RM} ${PREFIX}/share/lush/src/*c.orig

.include "../../math/gsl/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
