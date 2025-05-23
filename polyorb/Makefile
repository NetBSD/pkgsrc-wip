# $NetBSD: Makefile,v 1.3 2024/11/14 14:00:00 dkazankov Exp $

DISTNAME=	polyorb-${PKGVERSION_NOREV}
PKGNAME=	polyorb-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	PolyORB
# Latest commit in 25.0 branch
GITHUB_TAG=	43673925892098c14daca8b9b66c5017887b71d8

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/PolyORB
COMMENT=	Polymorphic, reusable infrastructure for building distributed systems
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	awk gmake
GNU_CONFIGURE=	yes

CHECK_PIE_SKIP+=	bin/*

USE_LANGUAGES=	c ada

# See xmlada package for rationale
GCC_REQD+=	13

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

USE_PKGSRC_GCC_RUNTIME?=	no

.include "options.mk"

OVERRIDE_RELEASE_PLACEHOLDER=	25.0w
ADDITIONAL_VERSION_PLACEHOLDER=

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Set version
SUBST_VARS.version=	OVERRIDE_RELEASE_PLACEHOLDER ADDITIONAL_VERSION_PLACEHOLDER
SUBST_FILES.version=	configure

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--with-appli-perso=${APP_PERSONALITIES:Q}
CONFIGURE_ARGS+=	--with-proto-perso=${PROTOCOL_PERSONALITIES:Q}
CONFIGURE_ARGS+=	--with-corba-services=${CORBA_SERVICES:Q}
EXTRA_GNATMAKE_FLAGS+=	-eL -R -largs $${LDFLAGS} -margs
CONFIGURE_ENV+=		EXTRA_GNATMAKE_FLAGS=${EXTRA_GNATMAKE_FLAGS:Q}

.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
CONFIGURE_ARGS+=			--enable-shared
CONFIGURE_ARGS+=			--with-gprbuild=gprbuild
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.else
CONFIGURE_ARGS+=			--disable-shared
.endif

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin include lib \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
