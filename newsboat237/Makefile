# $NetBSD$

DISTNAME=	newsboat-2.37
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	https://newsboat.org/releases/2.37/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://newsboat.org/
COMMENT=	RSS/Atom feed reader for the text console
LICENSE=	mit

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		awk gmake msgfmt pkg-config
USE_GNU_ICONV=		yes
USE_CURSES=		wide
FAKE_NCURSES=		yes

GMAKE_REQD=		4.0

TOOL_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor>=1.5.3:../../textproc/ruby-asciidoctor
TOOLS_CREATE+=		asciidoctor
TOOLS_PATH.asciidoctor=	${TOOLBASE}/bin/asciidoctor${RUBY_SUFFIX}

BUILD_TARGET=	all doc

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
MAKE_ENV+=	CXX_FOR_BUILD=${NATIVE_CXX:Q}
MAKE_ENV+=	CARGO_BUILD_TARGET=${RUST_ARCH:Q}
.endif
MAKE_ENV+=	GETTEXT_LIB_DIR=${BUILDLINK_PREFIX.gettext:Q}/lib
MAKE_ENV+=	GETTEXT_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext:Q}/include
MAKE_ENV+=	GETTEXT_BIN_DIR=${TOOLBASE:Q}/bin

MAKE_FLAGS+=	prefix=${PREFIX:Q} mandir=${PREFIX:Q}/${PKGMANDIR:Q}

do-build: do-newsboat-build
do-newsboat-build: .PHONY
do-newsboat-build: do-cargo-build
	${RUN}cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${BUILD_TARGET}

do-install:
	${RUN}cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} ${INSTALL_TARGET}

.include "cargo-depends.mk"

RUST_REQ=	1.77.0
.include "../../lang/rust/cargo.mk"

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.5
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.stfl+=	stfl>=0.21
.include "../../devel/stfl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
BUILDLINK_API_DEPENDS.json-c+=	json-c>=0.11
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.curl+=	curl>=7.32.0
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
