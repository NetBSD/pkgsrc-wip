# $NetBSD: Makefile,v 1.3 2003/12/01 03:14:06 mpasternak Exp $
#
# This is ripped devel/libtool-base/Makefile, that will generate a libtool 
# script, that will, in turn, allow cross-compilation with mingw32
#
# WARNING: this is a hack of a hack of a hack of a hack. I just want to
# get on this quick and test. We can clean code later. This is pre-alpha
# quality.
# 

DISTNAME=	libtool-ml-20010614
PKGNAME=	mingw-libtool-20010614
WRKSRC=		${WRKDIR}/libtool-ml
CATEGORIES=	devel pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.gnu.org/software/libtool/libtool.html
COMMENT=	Generic shared library support script (the script itself) for mingw

NO_CONFIGURE=	# defined
NO_BUILDLINK=	# defined

do-build:
	cd ${WRKSRC} && ${SETENV} PATH=${PATH} ./configure --host=${MINGWTARGET} --disable-ltdl-install 
	cd ${WRKSRC} && ${SETENV} PATH=${PATH} ${GMAKE}
	cd ${WRKSRC} && ${CP} libtool libtool.orig
	cd ${WRKSRC} && ${CAT} ${.CURDIR}/files/patch-aa | ${PATCH} -p0

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libtool ${CROSSBASE}/${MINGWTARGET}/bin

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
