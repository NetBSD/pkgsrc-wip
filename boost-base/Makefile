# $NetBSD: Makefile,v 1.4 2004/05/10 21:34:51 blef Exp $
#

DISTNAME=		boost_1_30_0
PKGNAME=		boost-base-1.30.0
CATEGORIES=		devel
# change to http://boost.sourceforge.net/release when becomes available
MASTER_SITES=	http://twtelecom.dl.sourceforge.net/sourceforge/boost/

MAINTAINER=		felix@students.poly.edu
HOMEPAGE=		http://www.boost.org/
COMMENT=		Free, portable c++ libraries that integrate with C++ Standard library

CONFLICTS=		boost-1.28.0

USE_BUILDLINK3=		yes
INCDIR=			${PREFIX}/include
SHAREDIR=		${PREFIX}/share/doc/html/boost

pre-configure:
	${CP} ${FILESDIR}/user.hpp ${WRKSRC}/boost/config/user.hpp

#building bjam places it in /tools/build/jam_src/bin.netbsd/bjam
do-build:
	cd ${WRKSRC}/tools/build/jam_src; ${SH} ./build.sh

do-install:
	${CP} -R ${WRKSRC}/boost ${INCDIR}
	${CP} -R ${WRKSRC}/doc/html ${SHAREDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INCDIR}/boost ${SHAREDIR}
	${CHMOD} -R a+r-w ${INCDIR}/boost ${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/jam_src/bin.*/bjam \
		${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
