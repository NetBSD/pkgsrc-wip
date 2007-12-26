# $NetBSD: Makefile,v 1.7 2007/12/26 17:31:40 bsadewitz Exp $
#

PKGNAME=	${DISTNAME:C/[[:alnum:]]*/&-base/}

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

MPG123_SUBDIRS=		src doc
MPG123_SUBDIRS.src=	output libmpg123

MPG123_MODULE=		dummy
MAKE_ENV+=		MPG123_PROGRAM=mpg123
MAKE_ENV+=		EXTRA_INSTALL_TARGETS="install-exec-am install-data-am"

MPG123_BUILDING_BASE=	# defined

.include "options.mk"

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
