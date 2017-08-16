# $NetBSD: Makefile,v 1.7 2014/01/01 23:34:14 cheusov Exp $
#

PKGNAME=	lmdbg-9
CATEGORIES=	devel
MASTER_SITES=	#
DISTNAME=	#

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger
LICENSE=	mit

GIT_REPOSITORIES=	lmdbg
GIT_REPO.lmdbg=		git://github.com/cheusov/lmdbg.git
.include "../../wip/mk/git-package.mk"

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=		runawk>=1.3.1:../../lang/runawk
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

WRKSRC=			${WRKDIR}/lmdbg

ONLY_FOR_COMPILER=	gcc icc clang
NOT_FOR_PLATFORM=	Darwin-*-*

TEST_TARGET=		test

REPLACE_SH=		scripts/lmdbg*.in tests/test.sh

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/lmdbg-*.in

MAKE_ENV+=		AWK=${AWK:Q}

post-install:
	cd ${WRKSRC} && \
	${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install-doc

.include "../../devel/mk-configure/mk-c.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
