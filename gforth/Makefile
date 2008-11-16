# $NetBSD: Makefile,v 1.7 2008/11/16 07:28:25 asau Exp $

DISTNAME=	gforth-0.7.99
PKGNAME=	gforth-0.7.99 # needed because of cvs-package.mk
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gforth/} \
		http://www.complang.tuwien.ac.at/forth/gforth/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=	Fast interpreter for the Forth language

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 *-*-m68k *-*-powerpc *-*-sparc

CVS_REPOSITORIES=	gforth
CVS_ROOT.gforth=	:pserver:anonymous:@c1.complang.tuwien.ac.at:/nfs/unsafe/cvs-repository/src-master

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes

WRKSRC=		${WRKDIR}/gforth

# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake aclocal
USE_TOOLS+=	makeinfo gzip
USE_TOOLS+=	perl:build

MAKE_JOBS_SAFE=	no # fresh Gforth is required to build doc
BUILD_TARGET=	all doc
TEST_TARGET=	check

INSTALLATION_DIRS=	share/emacs/site-lisp

pre-configure:
	${RUN} cd ${WRKSRC} && ${CONFIG_SHELL} autogen.sh

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/ffcall/buildlink3.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
