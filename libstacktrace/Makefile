# $NetBSD: Makefile,v 1.14 2012/08/31 19:45:30 cheusov Exp $
#

DISTNAME=	lmdbg-1.0.0
PKGNAME=	${DISTNAME:S/lmdbg-/libstacktrace-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Stacktracing library similar to glibc backtrace(3)
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure

ONLY_FOR_COMPILER=	gcc icc
NOT_FOR_PLATFORM=	Darwin-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/libstacktrace

MAKE_ENV+=		MKINSTALL=yes
MAKE_ENV+=		MKPROFILELIB=yes MKPICLIB=yes MKSTATICLIB=yes

MAKE_PROGRAM=		${PREFIX}/bin/mkcmake

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
