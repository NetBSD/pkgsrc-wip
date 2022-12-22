# $NetBSD$

DISTNAME=	v0.1
PKGNAME=	tpdne-dl-0.1
CATEGORIES=	graphics
MASTER_SITES=	https://codeberg.org/nanoory/TPDNE-dl/archive/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://codeberg.org/nanoory/TPDNE-dl/archive/
COMMENT=	Download tool for thispicturedoesnotexist.com
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/tpdne-dl
USE_LANGUAGES=	# Go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
