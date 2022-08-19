# $NetBSD$

DISTNAME=	muon-0.0.1
CATEGORIES=	devel
GIT_REPO=	https://git.sr.ht/~lattis/muon
GIT_BRANCH=	master
GIT_REVISION=	6b8073be2501abf34f488c46f9eca9958d702f8a

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~lattis/muon
COMMENT=	Implementation of meson build system in c99 with minimal dependencies
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	samurai>=1.2:../../devel/samurai

MESON_CFLAGS=	${CFLAGS:C/ /' c_args+='/Wg}
MESON_LDFLAGS=	${LDFLAGS:S/ /' link_args+='/Wg}

SUBST_CLASSES+=		flags1
SUBST_STAGE.flags1=	pre-configure
SUBST_MESSAGE.flags1=	Honor LDFLAGS in bootstrap.sh ...
SUBST_FILES.flags1=	bootstrap.sh
SUBST_SED.flags1=	-e 's, -o ,$$LDFLAGS -o,'

SUBST_CLASSES+=		flags2
SUBST_STAGE.flags2=	pre-configure
SUBST_MESSAGE.flags2=	Honor CFLAGS and LDFLAGS in meson.build ...
SUBST_FILES.flags2=	meson.build
SUBST_SED.flags2=	-e "s|@CFLAGS@|c_args+='${MESON_CFLAGS:S/ /@LF@/Wg}'|"
SUBST_SED.flags2+=	-e "s|@LDFLAGS@|link_args+='${MESON_LDFLAGS:S/ /@LF@/Wg}'|"
SUBST_SED.flags2+=	-e "s|@LF@|\\${.newline}|g"

INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ./bootstrap.sh bootstrap1
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ./bootstrap1/muon setup -Ddocs=disabled -Dstatic=false -Dlibcurl=disabled -Dlibarchive=disabled bootstrap2
	cd ${WRKSRC} && env ${CONFIGURE_ENV} samu -C bootstrap2

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ./bootstrap2/muon setup -Ddocs=disabled -Dstatic=false -Dlibcurl=disabled -Dlibarchive=disabled output
	cd ${WRKSRC} && env ${MAKE_ENV} samu -C output

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/muon \
		${DESTDIR}${PREFIX}/bin/muon

# Note: pkgconf library is included via hacks.mk
#.include "../../archivers/libarchive/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
