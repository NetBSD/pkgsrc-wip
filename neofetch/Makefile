# $NetBSD$

DISTNAME=	neofetch-6.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylanaraps/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dylanaraps/neofetch
COMMENT=	Command-line system information tool written in bash 3.2+
LICENSE=	mit

REPLACE_BASH+=	neofetch
USE_TOOLS+=	bash:run

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
