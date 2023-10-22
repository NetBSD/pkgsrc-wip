# $NetBSD$

DISTNAME=	newsboat-2.33
CATEGORIES=	news
MASTER_SITES=	https://newsboat.org/releases/2.33/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://newsboat.org/
COMMENT=	RSS/Atom feed reader for the text console
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt
USE_CURSES=	wide

REPLACE_PERL+=	txt2h

TOOL_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor>=1.5.3:../../textproc/ruby-asciidoctor
TOOL_DEPENDS+=		gettext-tools>=0:../../devel/gettext-tools
BUILD_TARGET=		all
FAKE_NCURSES=		yes

# The program tries to compile gettext if it does not find it 
# It checks environment variables, so we have to set them
MAKE_ENV+=	GETTEXT_LIB_DIR=${BUILDLINK_PREFIX.gettext-lib:Q}/lib
MAKE_ENV+=	GETTEXT_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext-lib:Q}/include
MAKE_ENV+=	GETTEXT_BIN_DIR=${TOOLBASE:Q}/bin

.include "cargo-depends.mk"


#Not sure if this is useful
#INSTALL_MAKE_FLAGS+=	prefix=${PREFIX} mandir=${PREFIX}/${PKGMANDIR}


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile...
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/^ifneq.*//; s/^endif.*//'
.endif


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/newsboat \
		${DESTDIR}${PREFIX}/bin


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/stfl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/rust/cargo.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
