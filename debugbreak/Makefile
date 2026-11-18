# $NetBSD$

DISTNAME=	debugbreak-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=scottt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scottt/debugbreak/
COMMENT=	Break into the debugger programmatically
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

INSTALLATION_DIRS+=	include share/debugbreak share/doc/debugbreak

# just builds testp programs
do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/debugbreak.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/debugbreak-gdb.py ${DESTDIR}${PREFIX}/share/debugbreak
	${INSTALL_DATA} ${WRKSRC}/*.md ${DESTDIR}${PREFIX}/share/doc/debugbreak

.include "../../mk/bsd.pkg.mk"
