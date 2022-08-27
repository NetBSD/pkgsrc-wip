# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	proton-bridge-2.2.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=ProtonMail/}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/ProtonMail/proton-bridge/
COMMENT=	ProtonMail Bridge application
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

do-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GMAKE} build-nogui

do-install:
	${INSTALL} ${WRKSRC}/proton-bridge ${DESTDIR}${PREFIX}/bin/

MAKE_ENV+=	GOOS=linux
MAKE_ENV+=	GO=${GO}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
