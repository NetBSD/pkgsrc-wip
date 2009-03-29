# $NetBSD: Makefile,v 1.1.1.1 2009/03/29 18:47:36 cheusov Exp $
#

DISTNAME=	lmdbg-0.10alpha1
PKGNAME=	${DISTNAME:S/lmdbg-/libstacktrace-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://mova.org/~cheusov/pub/lmdbg/
COMMENT=	Stacktracing library

BUILD_DEPENDS+=		mk-configure>=0.9.0:../../wip/mk-configure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/libstacktrace

USE_BSD_MAKEFILE=	yes

DISTINFO_FILE=		${.CURDIR}/../../wip/lmdbg/distinfo

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		${PREFIX}/bin/bmake
