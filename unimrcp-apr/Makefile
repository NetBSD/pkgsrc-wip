# $NetBSD$

DISTNAME=	apr-1.5.2
CATEGORIES=	devel
MASTER_SITES=	https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	apr-1.5.2-patches.tar.gz
SITES.apr-1.5.2-patches.tar.gz=	https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/
COMMENT=	Patched APR version for UniMRCP
LICENSE=	apache-2.0

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		pkg-config patch
PKGCONFIG_OVERRIDE+=	apr.pc.in

CONFIGURE_ARGS+=	--prefix=${PREFIX}/unimrcp/apr

post-extract:
	cd ${WRKDIR}/apr-1.5.2 && \
	${PATCH} -p1 < ../apr-1.5.2-patches/0001-Applied-thread-safety-patch-for-APR-memory-pools.patch; \
	${PATCH} -p1 < ../apr-1.5.2-patches/0003-Added-pre-generated-apr_escape_test_char.h-for-unix-.patch; \
	${PATCH} -p1 < ../apr-1.5.2-patches/0004-Added-project-files-for-VS2005-and-VS2010.patch; \
	${PATCH} -p1 < ../apr-1.5.2-patches/0005-Modified-libapr.rc-file-to-be-able-to-open-it-in-Res.patch; \
	${PATCH} -p1 < ../apr-1.5.2-patches/0006-Added-_WIN64-preprocessor-definition-for-x64-targets.patch

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
