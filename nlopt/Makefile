# $NetBSD$

DISTNAME=		nlopt-2.6.2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=stevengj/}
GITHUB_PROJECT=		nlopt
GITHUB_TAG=		v${PKGVERSION_NOREV}
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://nlopt.readthedocs.io/en/latest/
COMMENT=		Nonlinear optimization library
LICENSE=		gnu-lgpl-v2.1 OR mit

USE_TOOLS+=		cmake
USE_CMAKE=		yes
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		rbtree
CH_FILES_CMD=		cd ${WRKSRC} && ${FIND} . -name '*.[ch]'
SUBST_FILES.rbtree+=	${CH_FILES_CMD:sh}
SUBST_MESSAGE.rbtree=	Changing rb_tree symbols that collide with NetBSD libc.
SUBST_SED.rbtree=	-e "s|rb_tree_|nlopt_rb_tree_|g"
SUBST_STAGE.rbtree=	post-extract

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
