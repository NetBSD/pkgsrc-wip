# $NetBSD$

DISTNAME=	end_of_eden-0.1.11
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=BigJk/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	b17fbf50ab02082eef88b484ec82c965f0a53bcb

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BigJk/end_of_eden/
COMMENT=	"Slay the Spire"-like roguelite fully in console
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config
MAKE_ENV+=	CGO_ENABLED=1

# avoid oto dependency, since 0.7.0 doesn't support NetBSD (2.0+ does)
GO_BUILD_PATTERN=	-tags no_audio ./...

BUILDLINK_TRANSFORM+=	rm:-ldl

INSTALLATION_DIRS+=	libexec/end_of_eden share/end_of_eden

post-build:
	${ECHO} '#/bin/sh' > ${WRKSRC}/end_of_eden.sh
	${ECHO} 'cd ${PREFIX}/share/end_of_eden && ${PREFIX}/libexec/end_of_eden/game "$$@"' >> ${WRKSRC}/end_of_eden.sh
	${CHMOD} 755 ${WRKSRC}/end_of_eden.sh

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} game ../libexec/end_of_eden && \
		${MV} game_win ../libexec/end_of_eden && \
		${RM} *
	${INSTALL_SCRIPT} ${WRKSRC}/end_of_eden.sh ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${PAX} -pp -rw assets ${DESTDIR}${PREFIX}/share/end_of_eden/

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
