# $NetBSD$

DISTNAME=	ooRexx-svn-5.0.0
PKGNAME=	${DISTNAME:S/R/r/}
CATEGORIES=	lang
SVN_REPO=	https://svn.code.sf.net/p/oorexx/code-0/main/trunk
LICENSE=	gnu-gpl-v2 AND cpl-1.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oorexx.sourceforge.net/
COMMENT=	Powerful typeless object-oriented scripting language

CONFLICTS=	rexx-imc-[0-9]* rexx-regina-[0-9]*

USE_TOOLS+=	gmake
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DORX_SHEBANG=1

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/lib

# try to force use of ncurses
USE_CURSES=	chgat getmouse mvwchgat putwin

.include "../../wip/mk/svn-package.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
