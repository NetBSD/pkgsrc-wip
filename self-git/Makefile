# $NetBSD$

PKGNAME=	self
CATEGORIES=	lang
GIT_REPO=	http://github.com/russellallen/self.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.selflanguage.org/
COMMENT=	Prototype-based dynamic object-oriented programming language
# BSD?
# LICENSE=

USE_LANGUAGES=	c c++

USE_CMAKE=	yes

BUILDLINK_TRANSFORM+=	rm:-O2

CFLAGS+=	-I/usr/X11R7/include
CXXFLAGS+=	-I/usr/X11R7/include

.include "../../wip/mk/git-package.mk"

USE_X11=	yes

X11_LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/emul/netbsd32/lib
X11_LDFLAGS+=	-L${PREFIX}/emul/netbsd32/lib

BUILTIN_INCLUDE_DIRS+=	-I/usr/X11/include/

.include "../../wip/compat80-x11/buildlink3.mk"
#.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
