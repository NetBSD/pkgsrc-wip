# $NetBSD$

PKGNAME=	purple-teams-0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=EionRobb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EionRobb/purple-teams
COMMENT=	MS Teams protocol plugin for libpurple
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

GIT_REPOSITORIES=		purple-teams
GIT_REPO.purple-teams=		https://github.com/EionRobb/purple-teams
WRKSRC=				${WRKDIR}/purple-teams

.include "../../chat/libpurple/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
