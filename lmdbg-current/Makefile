# $NetBSD: Makefile,v 1.4 2012/03/10 06:43:11 cheusov Exp $
#

PKGNAME=	lmdbg-${_CVS_PKGVERSION:S/.//g}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	#
DISTNAME=	#

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=		runawk>=1.3.1:../../lang/runawk
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

CVS_ROOT.lmdbg=		:pserver:anonymous:@mova.org:/home/cvsroot
CVS_REPOSITORIES=	lmdbg

WRKSRC=			${WRKDIR}/lmdbg

ONLY_FOR_COMPILER=	gcc icc clang
NOT_FOR_PLATFORM=	Darwin-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		test

REPLACE_SH=		scripts/lmdbg*.in tests/test.sh

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/lmdbg-*.in

post-install:
	cd ${WRKSRC} && \
	${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install-doc

.include "../../devel/mk-configure/mk-c.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
