# $NetBSD: Makefile,v 1.1.1.1 2011/11/18 13:23:51 cheusov Exp $
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
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

CVS_ROOT.lmdbg=		:pserver:anonymous:@mova.org:/home/cvsroot
CVS_REPOSITORIES=	lmdbg

WRKSRC=			${WRKDIR}/lmdbg

ONLY_FOR_COMPILER=	gcc icc
NOT_FOR_PLATFORM=	Darwin-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		test

DOCDIR=			share/doc/lmdbg
DOCFILES=		README NEWS

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/lmdbg-*.in
DEPENDS+=		runawk>=1.3.1:../../lang/runawk

INSTALLATION_DIRS=	${DOCDIR}

MAKE_PROGRAM=	${PREFIX}/bin/mkcmake

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../wip/mk/cvs-package.mk"
.include "../../devel/mk-configure/configure.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
