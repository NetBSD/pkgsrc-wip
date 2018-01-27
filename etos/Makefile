# $NetBSD: Makefile,v 1.1 2014/07/28 17:32:04 jihbed Exp $

DISTNAME=	etos-3.1.4
CATEGORIES=	biology
MASTER_SITES=	http://garr.dl.sourceforge.net/project/etos/3.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://etos.sourceforge.net/
COMMENT=	Efficient technology of spike-sorting
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yesUSE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

GCC_REQD+=	4.2


.include "../../graphics/glut/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../parallel/openmpi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
