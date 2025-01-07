# $NetBSD$

DISTNAME=	nativefiledialog-extended-1.2.1
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=btzy/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/btzy/nativefiledialog-extended/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
