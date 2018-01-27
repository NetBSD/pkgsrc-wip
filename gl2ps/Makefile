# $NetBSD$

DISTNAME=	gl2ps-1.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://geuz.org/gl2ps/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	http://geuz.org/gl2ps/
COMMENT=	OpenGL to PostScript printing library
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/gl2ps-1.4.0-source
USE_CMAKE=	yes

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
