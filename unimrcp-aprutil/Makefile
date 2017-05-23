# $NetBSD$

DISTNAME=	apr-util-1.5.4
CATEGORIES=	devel
MASTER_SITES=	https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	apr-util-1.5.4-patches.tar.gz
SITES.apr-util-1.5.4-patches.tar.gz= https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/
COMMENT=	Patched APR-UTIL version for UniMRCP
LICENSE=	apache-2.0

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		pkg-config patch
PKGCONFIG_OVERRIDE+=	apr-util.pc.in

CONFIGURE_ARGS+=	--prefix=${PREFIX}/unimrcp/apr
CONFIGURE_ARGS+=	--with-apr=${PREFIX}/unimrcp/apr

post-extract:
	cd ${WRKDIR}/apr-util-1.5.4 && \
	${PATCH} -p1 < ../apr-util-1.5.4-patches/0001-Fixed-compilation-warning-in-apr_thread_pool.c-while.patch; \
	${PATCH} -p1 < ../apr-util-1.5.4-patches/0002-Fixed-compilation-warnings-in-expat-while-building-f.patch; \
	${PATCH} -p1 < ../apr-util-1.5.4-patches/0003-Added-project-files-for-VS2005-and-VS2010.patch; \
	${PATCH} -p1 < ../apr-util-1.5.4-patches/0004-Modified-libaprutil.rc-file-to-be-able-to-open-it-in.patch; \
	${PATCH} -p1 < ../apr-util-1.5.4-patches/0005-Added-_WIN64-preprocessor-definition-for-x64-targets.patch; \
	${PATCH} -p1 < ../apr-util-1.5.4-patches/0006-Added-a-new-APU-feature-macro-APR_HAS_QUEUE_TIMEOUT-.patch; \
	${PATCH} -p1 < ../apr-util-1.5.4-patches/0007-Added-a-missing-include-for-apr_time.h-in-apr_queue..patch

.include "../../wip/unimrcp-apr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
