# $NetBSD: Makefile,v 1.8 2007/12/28 02:54:36 bsadewitz Exp $
#

PKGNAME=	${DISTNAME:C/[^[:alnum:]]*//}
COMMENT=	MPEG layer 1, 2, and 3 audio player

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

MPG123_SUBDIRS=		src doc
MPG123_SUBDIRS.src=	output libmpg123

MPG123_MODULE=		dummy
MAKE_ENV+=		MPG123_PROGRAM=mpg123
MAKE_ENV+=		EXTRA_INSTALL_TARGETS="install-exec-am install-data-am"

MPG123_BUILDING_BASE=	# defined

.include "options.mk"

.include "Makefile.common"

#post-extract:
#	${RUN} cp ${FILESDIR}/debug.c ${WRKSRC}/src/libmpg123

.include "../../mk/bsd.pkg.mk"
