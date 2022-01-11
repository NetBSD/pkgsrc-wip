# $NetBSD: Makefile,v 1.1 2015/09/08 12:45:54 thomasklausner Exp $

DISTNAME=	gonepass-0.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/jbreams/gonepass/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbreams/gonepass/
COMMENT=	Password manager compatible with 1Password (git version)
LICENSE=	apache-2.0

GIT_REPOSITORIES=	gonepass
GIT_REPO.gonepass=	https://github.com/jbreams/gonepass.git
WRKSRC=			${WRKDIR}/gonepass

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	build

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/glib2/schemas.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
