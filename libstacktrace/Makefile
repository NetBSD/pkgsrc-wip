# $NetBSD: Makefile,v 1.4 2010/01/03 13:15:04 cheusov Exp $
#

DISTNAME=	lmdbg-0.12.0
PKGNAME=	${DISTNAME:S/lmdbg-/libstacktrace-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Stacktracing library

BUILD_DEPENDS+=		mk-configure>=0.13.0:../../wip/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/libstacktrace

USE_BSD_MAKEFILE=	yes
MAKE_ENV+=		MKINSTALL=yes MKPROFILE=yes
MAKE_ENV+=		MKPIC=yes MKPICINSTALL=yes

DISTINFO_FILE=		${.CURDIR}/../../wip/lmdbg/distinfo

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		${PREFIX}/bin/bmake
