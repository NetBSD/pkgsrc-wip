# $NetBSD$

DISTNAME=	sparse-0.5.0
CATEGORIES=	devel
MASTER_SITES=	https://www.kernel.org/pub/software/devel/sparse/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kernel.org/pub/software/devel/sparse/dist/
COMMENT=	Semantic Parser for C
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	sparse.pc.in

SUBST_CLASSES=			installflags
SUBST_STAGE.installflags=	post-patch
SUBST_FILES.installflags=	Makefile
SUBST_SED.installflags=		-e 's,install -v,install,g'
SUBST_MESSAGE.conf=		Remove verbose flag for install


#.include "../../lang/llvm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
