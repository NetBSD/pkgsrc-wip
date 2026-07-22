# $NetBSD$

VERSION=	0.0.1
DISTNAME=	async-process-${VERSION}
PKGNAME=	cl-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lem-project/}
GITHUB_TAG=	3ea46fcd238fdda101b644221ecf5e311c171a21
GITHUB_TYPE=	tag

WRKSRC=	${WRKDIR}/${DISTNAME:S/-${VERSION}//}-${GITHUB_TAG}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/lem-project/async-process/
COMMENT=	Common Lisp asynchronous processes library
LICENSE=	mit

USE_LANGUAGES=	c

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

.include "../../mk/bsd.pkg.mk"
