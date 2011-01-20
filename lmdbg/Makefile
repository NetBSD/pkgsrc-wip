# $NetBSD: Makefile,v 1.22 2011/01/20 23:25:00 cheusov Exp $
#

DISTNAME=	lmdbg-0.16.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger
LICENSE=		mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		test

MAKE_ENV=		MANDIR=${PREFIX}/${PKGMANDIR}

DOCDIR=			share/doc/lmdbg
DOCFILES=		README NEWS ChangeLog

AUTO_MKDIRS=		yes

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	${PREFIX}/bin/mkcmake
