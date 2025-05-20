# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

DISTNAME=	gprbuild-${PKGVERSION_NOREV}
PKGNAME=	gprlib-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gprbuild
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gprbuild
COMMENT=	LIBGPR development libraries
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

USE_LANGUAGES=	c ada

# GPRLIB 25 uses -gnat2020 switch
GCC_REQD+=	13

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=			getrusage
SUBST_MESSAGE.getrusage=	Replace getrusage with __netbsd_getrusage in ${SUBST_FILES.getrusage}
SUBST_STAGE.getrusage=		pre-configure
SUBST_FILES.getrusage=		gpr/src/gpr-util-put_resource_usage__unix.adb
SUBST_SED.getrusage=		-e "s,\"getrusage\",\"__netbsd_getrusage\","
.endif

CONFIGURE_ARGS+=	prefix=${DESTDIR}${PREFIX}

do-configure:
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${CONFIGURE_ENV} \
	${MAKE_PROGRAM} ${CONFIGURE_ARGS} setup

BUILD_TARGET=		libgpr.build
INSTALL_TARGET=		libgpr.install

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../wip/xmlada/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
