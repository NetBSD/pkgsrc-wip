# $NetBSD$

DISTNAME=	tidy-html5-5.1.25
PKGNAME=	${DISTNAME:S/-html5//}
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=htacg/}
GITHUB_PROJECT=	tidy-html5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.html-tidy.org/
COMMENT=	Fixes and tidies up HTML files
LICENSE=	mit

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
