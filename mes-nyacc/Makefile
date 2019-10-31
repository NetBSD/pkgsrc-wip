# $NetBSD$

DISTNAME=	nyacc-v0.80.43
PKGNAME=	mes-${DISTNAME:S/v//}
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/janneke/nyacc/-/archive/v0.80.43/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://gitlab.com/janneke/nyacc/
COMMENT=	NYACC (Not Yet Another Compiler Compiler) with patches for mes
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3
USE_TOOLS+=	gmake

HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--prefix=${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib
CONFIGURE_ARGS+=	--site_scm_dir=${PREFIX}/guile/2.2/share/guile/2.2
CONFIGURE_ARGS+=	--site_scm_go_dir=${PREFIX}/guile/2.2/lib/guile/2.2/site-ccache

TEST_TARGET=	check

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
