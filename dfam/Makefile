# $NetBSD$

DISTNAME=	Dfam.h5
PKGNAME=	dfam-3.5
CATEGORIES=	biology
MASTER_SITES=	https://www.dfam.org/releases/Dfam_3.5/families/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dfam.org/home
COMMENT=	Collection of genome annotation data
LICENSE=	cc0-1.0-universal

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/${PKGNAME_NOREV}

do-install:
	${INSTALL_DATA} ${WRKSRC}/Dfam.h5 ${DESTDIR}${PREFIX}/share/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
