# $NetBSD$

DISTNAME=	svt-vp9-0.3.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenVisualCloud/}
GITHUB_PROJECT=	SVT-VP9
GITHUB_TAG=	v0.3.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenVisualCloud/SVT-VP9/
COMMENT=	VP9 encoder
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_CMAKE=	yes

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

.include "../../mk/bsd.pkg.mk"
