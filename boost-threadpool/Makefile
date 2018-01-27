# $NetBSD: Makefile,v 1.2 2012/09/24 17:14:39 asau Exp $

DISTNAME=	threadpool-0_2_5-src
PKGNAME=	boost-${DISTNAME:S/_/./g:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=threadpool/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://threadpool.sourceforge.net/
COMMENT=	Cross-platform C++ thread pool library
LICENSE=	boost-license

EXTRACT_SUFX=		.zip
WRKSRC=			${WRKDIR}/${DISTNAME}/threadpool
INSTALLATION_DIRS=	include/boost
INSTALLATION_DIRS+=	include/boost/threadpool
INSTALLATION_DIRS+=	include/boost/threadpool/detail

.include "../../mk/bsd.prefs.mk"

do-build:
	${TRUE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/boost/threadpool.hpp ${DESTDIR}${PREFIX}/include/boost/threadpool.hpp
.for s in future.hpp pool.hpp pool_adaptors.hpp scheduling_policies.hpp \
	shutdown_policies.hpp size_policies.hpp task_adaptors.hpp
	${INSTALL_DATA} ${WRKSRC}/boost/threadpool/${s} \
		${DESTDIR}${PREFIX}/include/boost/threadpool/${s}
.endfor
.for s in future.hpp locking_ptr.hpp pool_core.hpp scope_guard.hpp \
	worker_thread.hpp
	${INSTALL_DATA} ${WRKSRC}/boost/threadpool/detail/${s} \
		${DESTDIR}${PREFIX}/include/boost/threadpool/detail/${s}
.endfor

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
