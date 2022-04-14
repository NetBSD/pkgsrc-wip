# $NetBSD$

DISTNAME=	sparse-0.6.4
CATEGORIES=	devel
MASTER_SITES=	https://www.kernel.org/pub/software/devel/sparse/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kernel.org/pub/software/devel/sparse/dist/
COMMENT=	Semantic Parser for C
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

REPLACE_PERL+=	cgcc
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	BINDIR=${PREFIX}/bin
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../lang/llvm/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
