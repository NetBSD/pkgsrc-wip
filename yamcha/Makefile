# $NetBSD: Makefile,v 1.1.1.1 2008/01/23 07:39:31 obache Exp $
#

DISTNAME=	yamcha-0.33
CATEGORIES=	devel
MASTER_SITES=	http://www.chasen.org/~taku/software/yamcha/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.chasen.org/~taku/software/yamcha/
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
