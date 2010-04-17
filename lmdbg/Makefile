# $NetBSD: Makefile,v 1.17 2010/04/17 20:30:05 cheusov Exp $
#

DISTNAME=	lmdbg-0.14.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger

LICENSE=		mit

BUILD_DEPENDS+=		mk-configure>=0.14.0:../../wip/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FLAGS+=		MKCATPAGES=no MKPICINSTALL=no MKPROFILE=no

TEST_TARGET=		test

DOCDIR=			share/doc/lmdbg

DOCFILES=		README NEWS ChangeLog

AUTO_MKDIRS=		yes

do-build:
	cd ${WRKSRC} && \
	env ${MAKE_ENV} mkcmake ${BUILD_MAKE_FLAGS} \
		-f ${MAKE_FILE} all

do-install:
	cd ${WRKSRC} && \
	env ${MAKE_ENV} mkcmake ${INSTALL_MAKE_FLAGS} \
		-f ${MAKE_FILE} install

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
