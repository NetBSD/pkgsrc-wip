# $NetBSD$

DISTNAME=	galene-1.2.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jech/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://galene.org/
COMMENT=	Videoconference server
LICENSE=	mit

MAKE_ENV+=	CGO_ENABLED=0

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Adjust paths for pkgsrc
SUBST_FILES.paths=	galene.go
SUBST_VARS.paths=	PREFIX

INSTALLATION_DIRS+=	share/galene/static

post-install:
	cd ${WRKSRC}/static && \
		${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/galene/static

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
