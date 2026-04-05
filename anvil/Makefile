# $NetBSD$

DISTNAME=	anvil-src-v0.7
PKGNAME=	${DISTNAME:S,-src-v,-,}
CATEGORIES=	editors
MASTER_SITES=	http://anvil-editor.net/releases/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	http://anvil-editor.net/
COMMENT=	Plan 9 acme-like editor written in Go
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	zip bash

GO_VERSION_REQD+=	124
GO_LDFLAGS+=		-r ${X11BASE}/lib:${PREFIX}/lib

WRKSRC=	${WRKDIR}/${DISTNAME}/anvil

INSTALLATION_DIRS+=	bin

# post-extract:
# 	${CP} ${WRKSRC}/fs_linux.go ${WRKSRC}/fs_netbsd.go


GO_BUILD_TAGS+=	-tags noegl

GO_CMD=	GOPATH=${WRKDIR}/.gopath ${GO} ${GOFLAGS} build
GO_CMD+=	${GO_BUILD_TAGS} -ldflags=${GO_LDFLAGS:Q}

SUBST_CLASSES+=		build
SUBST_STAGE.build=		pre-configure
SUBST_MESSAGE.build=	Use the pkgsrc go command
SUBST_FILES.build+=	build.sh
SUBST_SED.conf=		-e 's|@GO_CMD@|${GO_CMD:Q}|g'
SUBST_VARS.build+=		GO_CMD

MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

do-build:
	# TODO: doesn't compile on NetBSD
	${RM} -rf ${WRKSRC}/extras/cmd/awin
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${BASH} build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/anvil ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"
.include "go-modules-extra.mk"
.include "go-modules-work.mk"

.include "../../devel/wayland/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
