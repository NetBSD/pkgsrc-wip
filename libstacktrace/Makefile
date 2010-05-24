# $NetBSD: Makefile,v 1.5 2010/05/24 20:18:35 cheusov Exp $
#

DISTNAME=	lmdbg-0.14.0
PKGNAME=	${DISTNAME:S/lmdbg-/libstacktrace-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Stacktracing library similar to glibc backtrace(3)

BUILD_DEPENDS+=		mk-configure>=0.14.0nb1:../../wip/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/libstacktrace

MAKE_ENV+=		MKINSTALL=yes
MAKE_ENV+=		MKPROFILE=yes MKPIC=yes MKPICINSTALL=yes
MAKE_ENV+=		MKPROFILELIB=yes MKPICLIB=yes MKSTATICLIB=yes

DISTINFO_FILE=		${.CURDIR}/../../wip/lmdbg/distinfo

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		${PREFIX}/bin/mkcmake
