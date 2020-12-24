# $NetBSD$

GITHUB_PROJECT=	dosbox-staging
GITHUB_TAG=	v0.76.0
DISTNAME=	v0.76.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=dosbox-staging/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dosbox-staging.github.io/
COMMENT=	DOS/x86 emulator focusing on ease of use
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dosbox-staging-0.76.0
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	aclocal automake autoconf gmake pkg-config

NOT_PAX_MPROTECT_SAFE=	bin/dosbox_staging

pre-configure:
	${MV} ${WRKSRC}/docs/dosbox.1 ${WRKSRC}/docs/dosbox_staging.1
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
