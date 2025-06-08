# $NetBSD$

DISTNAME=	crosstool-ng-1.27.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=espressif/}
GITHUB_PROJECT=	crosstool-NG
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espressif/crosstool-NG/
COMMENT=	Cross compiler build for espressif esp32 processors
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-ncursesw
# XXX configure checks that EGREP is "grep -E"
CONFIGURE_ARGS+=	ac_cv_path_EGREP="/usr/bin/grep -E"

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake bash bison gawk gmake gsed

SUBST_CLASSES+=		unwrap
SUBST_FILES.unwrap+=	ct-ng
SUBST_FILES.unwrap+=	paths.sh
SUBST_STAGE.unwrap=	post-build
SUBST_SED.unwrap+=	-e "s,${TOOLS_DIR}/bin/bash,${BASH},"
# XXX: add full path?
SUBST_SED.unwrap+=	-e "s,${TOOLS_DIR}/bin/bison,bison,"
SUBST_SED.unwrap+=	-e "s,${TOOLS_DIR}/bin/make,${GMAKE},"
SUBST_MESSAGE.unwrap=	Fixing path to binaries.

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../mk/bsd.pkg.mk"
