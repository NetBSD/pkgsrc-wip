# $NetBSD: Makefile,v 1.2 2004/05/10 21:34:52 blef Exp $
#

DISTNAME=		boost_1_30_0
PKGNAME=		boost-thread-1.30.0
CATEGORIES=		devel
# change to http://boost.sourceforge.net/release when becomes available
MASTER_SITES=	http://twtelecom.dl.sourceforge.net/sourceforge/boost/

MAINTAINER=		felix@students.poly.edu
HOMEPAGE=		http://www.boost.org/
COMMENT=	 	Portable C++ multi-threading library

USE_BUILDLINK3=		yes
BOOST_HDRS= 		${BUILDLINK_PREFIX.boost-base}/include
BJAM=				${BUILDLINK_PREFIX.boost-base)/bin/bjam

# boost does not allow creation of staic-linked library for threads
# debug = symbols, #define DEBUG, no-inlining , -O
# release = no-symbols, #define NDEBUG, full-inlining, -O3
MAKE_ENV=	TOOLS=gcc
MAKE_ENV+=  BUILD="release debug <runtime-link>dynamic <include>${BOOST_HDRS}"
LIBS= 		libboost_thread.so libboost_threadd.so

do-build:
	cd ${WRKSRC}/libs/thread/build; ${MAKE_ENV} ${BJAM} -d2

do-install:
.for f in ${LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/libs/thread/build/bin-stage/$f ${PREFIX}/lib
.endfor

.include "../../wip/boost-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
