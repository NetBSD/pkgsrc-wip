# $NetBSD: Makefile,v 1.1.1.1 2003/11/30 23:54:33 mpasternak Exp $
#
# This is ripped devel/libtool-base/Makefile, that will generate a libtool 
# script, that will, in turn, allow cross-compilation with mingw32
#
# WARNING: this is a hack of a hack of a hack of a hack. I just want to
# get on this quick and test. We can clean code later. This is pre-alpha
# quality.
# 

.include "../../devel/libtool/Makefile.common"

PKGNAME=        mingw-${PKGPFX}
PKGREVISION=	# empty
COMMENT=	Generic shared library support script (the script itself) for mingw

NO_CONFIGURE=	# defined
NO_BUILDLINK=	# defined

do-build:
	cd ${WRKSRC} && ${SETENV} PATH=${PATH} ./configure --host=${MINGWTARGET} --disable-ltdl-install 
	cd ${WRKSRC} && ${SETENV} PATH=${PATH} ${GMAKE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libtool ${CROSSBASE}/${MINGWTARGET}/bin

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
