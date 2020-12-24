# $NetBSD$

DISTNAME=	jfsw-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonof/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jonof.id.au/jfsw
COMMENT=	JonoF's Shadow Warrior port
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/jfsw
USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c c++

BUILD_MAKE_FLAGS+=	LDFLAGS="${X11_LDFLAGS}"
GIT_REPOSITORIES=	jfsw
GIT_REPO.jfsw=		git://github.com/jonof/jfsw.git
INSTALLATION_DIRS+=	bin share/doc/jfsw
PKGCONFIG_OVERRIDE+=	jfbuild/libsquish/libsquish.pc.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sw ${DESTDIR}${PREFIX}/bin/jfsw
	${INSTALL_DATA} ${WRKSRC}/releasenotes.html ${DESTDIR}${PREFIX}/share/doc/jfsw/releasenotes.html

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
