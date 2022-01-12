# $NetBSD: Makefile,v 1.1 2021/10/12 08:50:00 dlb Exp $

.include "../../wip/mrust/Makefile.common"

PKGNAME=	mrust-minicargo-${SNAPSTAMP}
COMMENT=	Cargo workalike from the mrustc tool suite

BUILD_DIRS=	tools/minicargo

##MAKE_JOBS_SAFE=	no		# DLBFLAG: this may be needed

##UNLIMIT_RESOURCES=	stacksize	# DLBFLAG: stacksize doesn't need to
					# be unlimited, but does seem to
					# need to be higher than the default.
					# The value that worked for me was
					# 14m--but that probably could be
					# tuned (or, simply use this UNLIMIT
					# feature...?).

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++14


#* (no options yet) *#.include "options.mk"


####
# The source Makefile doesn't have an "install:" target.
# Use a simplistic workaround here.
# [DLBFLAG:] Lacks support for MS Windoes style ".exe" suffixes.
##
do-install:
	cd ${WRKSRC} && {                                               \
	    ${PKGSRC_SETENV} ${INSTALL_ENV}                             \
		${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin;         \
	    ${PKGSRC_SETENV} ${INSTALL_ENV}                             \
		${INSTALL} bin/minicargo ${DESTDIR}${PREFIX}/bin; }


.include "../../mk/bsd.pkg.mk"
