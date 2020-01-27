# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:06 asau Exp $
#

DISTNAME=	Singular-3-1-0-7
PKGNAME=	singular-3.1.0.7
CATEGORIES=	math
MASTER_SITES=	http://www.mathematik.uni-kl.de/ftp/pub/Math/Singular/SOURCES/3-1-0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.singular.uni-kl.de/
COMMENT=	SINGULAR is a Computer Algebra System for polynomial computations
LICENSE=	gnu-gpl-v3

DEPENDS+=	latex2html-[0-9]*:../../textproc/latex2html

WRKSRC=		${WRKDIR}/Singular-3-1-0
GNU_CONFIGURE=	yes
USE_TOOLS+=	perl gmake
USE_LANGUAGES=	c c++

#Arch support:
# Linux, HPUX, FreeBSD, etc...

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/ntl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
