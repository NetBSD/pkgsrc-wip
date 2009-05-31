# $NetBSD: Makefile,v 1.9 2009/05/31 12:55:53 cheusov Exp $
#

DISTNAME=	lmdbg-0.10.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Lightweight Malloc Debugger

BUILD_DEPENDS+=		mk-configure>=0.10.0:../../wip/mk-configure
DEPENDS+=		gdb-[0-9]*:../../devel/gdb

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes
INSTALL_DIRS=		scripts liblmdbg

MAKE_FLAGS+=		MKCATPAGES=no

TEST_TARGET=		test

DOCDIR=			share/doc/lmdbg

AUTO_MKDIRS=		yes

DOCFILES=		README NEWS ChangeLog

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		${PREFIX}/bin/bmake
