# $NetBSD$

DISTNAME=	edid-decode-0.1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.linuxtv.org/edid-decode.git/about/
COMMENT=	Decode EDID information from monitors
LICENSE=	mit

GIT_REPO=	https://git.linuxtv.org/edid-decode.git
CHECKOUT_DATE=	2021-12-09

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

MAKE_ENV+=	bindir=${PREFIX}/bin
MAKE_ENV+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
