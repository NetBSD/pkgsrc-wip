# $NetBSD: Makefile,v 1.2 2010/01/13 10:45:11 obache Exp $
#

.include "Makefile.common"

CATEGORIES=	devel

COMMENT=	Yet Another Multipurpose CHunk Annotator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

FIND_PREFIX:=	TINYSVMDIR=TinySVM
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}
CONFIGURE_ARGS+=	--with-svm-learn=${TINYSVMDIR}/bin/svm_learn

TEST_TARGET=	check

.include "../../wip/TinySVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
