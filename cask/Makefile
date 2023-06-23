# $NetBSD$

DISTNAME=	cask-0.8.8
CATEGORIES=	editors devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cask/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cask/cask/
COMMENT=	Project management tool for Emacs
LICENSE=	gnu-gpl-v3

DEPENDS+=	emacs28-[0-9]*:../../editors/emacs28

USE_LANGUAGES=	# none
USE_TOOLS+=	bash gmake

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
