# $NetBSD: Makefile,v 1.3 2024/11/14 14:00:00 dkazankov Exp $

PKGNAME=	polyorb-25.0.0
CATEGORIES=	devel
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/PolyORB
COMMENT=	PolyORB is a polymorphic, reusable infrastructure for building object-oriented distributed systems
LICENSE=	gnu-gpl-v2

DISTNAME=	polyorb-${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
# Latest commit in 25.0 branch
GITHUB_TAG=	43673925892098c14daca8b9b66c5017887b71d8
GITHUB_PROJECT=	PolyORB

USE_TOOLS+=	awk autoconf automake gmake
GNU_CONFIGURE=	yes

CHECK_PIE_SKIP+=	bin/*

USE_LANGUAGES=	c ada

GCC_REQD+=	13

OVERRIDE_RELEASE_PLACEHOLDER=	25.0w
ADDITIONAL_VERSION_PLACEHOLDER=

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Set version
SUBST_VARS.version=	OVERRIDE_RELEASE_PLACEHOLDER ADDITIONAL_VERSION_PLACEHOLDER
SUBST_FILES.version=	configure

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

OBJDIR=	${WRKDIR}/build

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--with-appli-perso=${APP_PERSONALITIES:Q}
CONFIGURE_ARGS+=	--with-proto-perso=${PROTOCOL_PERSONALITIES:Q}
CONFIGURE_ARGS+=	--with-corba-services=${CORBA_SERVICES:Q}

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

EXTRA_GNATMAKE_FLAGS+=	-eL -R -largs $${LDFLAGS} -margs
BUILD_MAKE_FLAGS+=	EXTRA_GNATMAKE_FLAGS=${EXTRA_GNATMAKE_FLAGS:Q}

.include "../../lang/gcc13-gnat-libs/buildlink3.mk"
.include "../../wip/gprbuild/buildlink3.mk"

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPMETHOD.xmlada=	full
.include "../../wip/xmlada/buildlink3.mk"

.include "../../wip/gprlib/buildlink3.mk"
.include "../../wip/gnatcoll-core/buildlink3.mk"

PYTHON_VERSIONS_ACCEPTED=	312 311 310 39 38
.include "../../lang/python/tool.mk"

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin include lib \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.pkg.mk"
