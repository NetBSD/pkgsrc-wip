# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 21:24:52 jihbed Exp $
#

DISTNAME=	Singular-3-1-0-7
PKGNAME=	singular-3.1.0.7
CATEGORIES=	math
MASTER_SITES=	http://www.mathematik.uni-kl.de/ftp/pub/Math/Singular/SOURCES/3-1-0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.singular.uni-kl.de/
COMMENT=	SINGULAR is a Computer Algebra System for polynomial computations
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	latex2html-[0-9]*:../../textproc/latex2html

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Singular-3-1-0
GNU_CONFIGURE=	yes
USE_TOOLS+=	perl gmake
USE_LANGUAGES=	c c++

#Arch support:
# Linux, HPUX, FreeBSD, etc...

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/ntl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
