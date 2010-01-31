# $NetBSD: Makefile,v 1.14 2010/01/31 19:57:34 cheusov Exp $
#

DISTNAME=	lmdbg-0.13.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Malloc Debugger

LICENSE=		mit

BUILD_DEPENDS+=		mk-configure>=0.14.0:../../wip/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../wip/pipestatus
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

MAKE_FLAGS+=		MKCATPAGES=no MKPICINSTALL=no MKPROFILE=no

TEST_TARGET=		test

DOCDIR=			share/doc/lmdbg

AUTO_MKDIRS=		yes

DOCFILES=		README NEWS ChangeLog

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		mkcmake
