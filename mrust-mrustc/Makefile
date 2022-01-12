# $NetBSD: Makefile,v 1.1 2021/10/12 08:50:00 dlb Exp $

.include "../../wip/mrust/Makefile.common"

PKGNAME=	mrust-mrustc-${SNAPSTAMP}
COMMENT=	Mutabah's Rust Compiler--the compiler itself

#CONFIGURE_ENV+=	disable_x11=yes

##TEST_PROGRAM=		local_tests
##MAKE_JOBS_SAFE=	no		# DLBFLAG: this may be needed
##UNLIMIT_RESOURCES=	stacksize	# DLBFLAG: stacksize doesn't need to
					# be unlimited, but does seem to
					# need to be higher than the default.
					# The value that worked for me was
					# 14m--but that probably could be
					# tuned (or, simply use this UNLIMIT
					# feature...?).


##USE_TOOLS+=		bash gmake
USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++14

#USE_GCC_RUNTIME=	yes		# DLBFLAG: will this be needed?

BUILD_MAKE_FLAGS=	GIT_L_HASH=${GITHUB_TAG}
BUILD_MAKE_FLAGS+=	GIT_S_HASH=${GITHUB_TAG:C/^(.......).*$/\1/W}


#* (no options yet) *#.include "options.mk"


do-install:
	cd ${WRKSRC} && {                                               \
	    ${PKGSRC_SETENV} ${INSTALL_ENV}                             \
		${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin;         \
	    ${PKGSRC_SETENV} ${INSTALL_ENV}                             \
		${INSTALL} bin/mrustc ${DESTDIR}${PREFIX}/bin; }


.include "../../mk/bsd.pkg.mk"
