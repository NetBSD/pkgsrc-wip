# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

DISTNAME=	gnatcoll-core-${PKGVERSION_NOREV}
PKGNAME=	gnatcoll-core-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-core
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoll-core
COMMENT=	The GNAT Components Collection (GNATcoll) - Core packages
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

USE_LANGUAGES=	c ada

GCC_REQD+=	13

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		ldl
SUBST_MESSAGE.ldl=	Fix extra libs on NetBSD in ${SUBST_FILES.ldl}
SUBST_STAGE.ldl=	pre-configure
SUBST_FILES.ldl=	core/gnatcoll_core.gpr
SUBST_SED.ldl=		-e "s,\"-ldl\",\"\","

SUBST_CLASSES+=		opendir
SUBST_MESSAGE.opendir=	Replace opendir with __gnatcoll_opendir in ${SUBST_FILES.opendir}
SUBST_STAGE.opendir=	pre-configure
SUBST_FILES.opendir=	core/src/os/unix/gnatcoll-os-libc-dirent.ads
SUBST_SED.opendir=	-e "s,\"opendir\",\"__gnatcoll_opendir\","
.endif

MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD

.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
MAKE_FLAGS+=			ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada=	full
BUILDLINK_DEPMETHOD.gprlib=	full
.else
MAKE_FLAGS+=			ENABLE_SHARED=no
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../wip/xmlada/buildlink3.mk"
.include "../../wip/gprlib/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
