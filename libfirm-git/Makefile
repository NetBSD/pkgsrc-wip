# $NetBSD$

PKGNAME=	libfirm-0
CATEGORIES=	devel

GIT_REPOSITORIES=	libfirm
GIT_REPO.libfirm=	https://github.com/MatzeB/libfirm.git

WRKSRC=		${WRKDIR}/libfirm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pp.ipd.kit.edu/firm
COMMENT=	C-Library suitable for optimizing compilers
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
#USE_CMAKE=	yes

USE_TOOLS+=	perl
USE_TOOLS+=	gmake

REPLACE_PERL+=	ir/be/scripts/generate_emitter.pl
REPLACE_PERL+=	ir/be/scripts/generate_new_opcodes.pl
REPLACE_PERL+=	ir/be/scripts/generate_regalloc_if.pl

REPLACE_PYTHON+=	scripts/gen_ir.py
REPLACE_PYTHON+=	support/statev_sql.py

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
