# $NetBSD: Makefile,v 1.1.1.1 2007/01/29 22:20:29 thomasklausner Exp $
#

DISTNAME=	cdrkit-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cdrkit.org/
COMMENT=	Portable command-line CD/DVD recorder software

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man page installation paths.
SUBST_FILES.manpath=	3rd-party/dirsplit/CMakeLists.txt
SUBST_FILES.manpath+=	3rd-party/zisofs_tools/CMakeLists.txt
SUBST_FILES.manpath+=	wodim/CMakeLists.txt
SUBST_FILES.manpath+=	genisoimage/CMakeLists.txt
SUBST_FILES.manpath+=	icedax/CMakeLists.txt
SUBST_FILES.manpath+=	readom/CMakeLists.txt
SUBST_SED.manpath=	-e "s,share/man,${PKGMANDIR},"

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
