# $NetBSD$

DISTNAME=	Molsketch-0.6.0-src
PKGNAME=	${DISTNAME:S/-src//:tl}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=molsketch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/molsketch/files/Molsketch/Nitrogen%200.6.0/Molsketch-0.6.0-src.tar.gz/
COMMENT=	Program for drawing molecular structures
LICENSE=	gnu-gpl-v2

USE_TOOLS=	pkg-config

USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_LANGUAGES=	c c++

.include "../../biology/openbabel/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
