# $NetBSD: Makefile,v 1.1 2012/09/03 23:06:17 jihbed Exp $
#

DISTNAME=	sympol-0.1.7
CATEGORIES=	math
MASTER_SITES=	http://www.math.uni-rostock.de/~rehn/software/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uni-rostock.de/~rehn/software/
COMMENT=	SymPol is a C++ tool to work with symmetric polyhedra
LICENSE=	gnu-gpl-v2

DEPENDS+=	lrslib>=4.3:../../wip/lrslib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		installman
SUBST_STAGE.installman=	pre-configure
SUBST_SED.installman+=	-e 's,share/man/man1,man/man1,g'
SUBST_FILES.installman+=	sympol/CMakeLists.txt
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
