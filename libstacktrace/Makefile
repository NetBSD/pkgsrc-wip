# $NetBSD: Makefile,v 1.8 2011/01/20 23:18:39 cheusov Exp $
#

DISTNAME=	lmdbg-0.15.1
PKGNAME=	${DISTNAME:S/lmdbg-/libstacktrace-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Stacktracing library similar to glibc backtrace(3)
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/libstacktrace

MAKE_ENV+=		MKINSTALL=yes
MAKE_ENV+=		MKPROFILELIB=yes MKPICLIB=yes MKSTATICLIB=yes

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		${PREFIX}/bin/mkcmake
