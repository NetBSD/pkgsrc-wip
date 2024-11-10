# $NetBSD$

DISTNAME=	mergiraf-0.2.0
CATEGORIES=	devel
MASTER_SITES=	-https://codeberg.org/mergiraf/mergiraf/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mergiraf.org/
COMMENT=	Sophisticated merge tool
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=			${WRKDIR}/mergiraf
USE_LANGUAGES=		c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
