# $NetBSD$

GITHUB_PROJECT=	fastfetch
GITHUB_TAG=	refs/tags/2.30.1
DISTNAME=	2.30.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=fastfetch-cli/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastfetch-cli/fastfetch/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/fastfetch-2.30.1
USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
