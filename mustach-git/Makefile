# $NetBSD$

DISTNAME=	mustach-0.0
CATEGORIES=	textproc
MASTER_SITES=	https://gitlab.com/jobol/mustach

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://gitlab.com/jobol/mustach
COMMENT=	C implementation of mustache templating
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/mustach

GIT_REPOSITORIES=	mustach
GIT_REPO.mustach=	https://gitlab.com/jobol/mustach.git

.include "../../textproc/json-c/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
