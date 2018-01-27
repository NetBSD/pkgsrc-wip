# $NetBSD$

DISTNAME=		dart-1.13.0
CATEGORIES=		lang
GIT_REPOSITORIES=	sdk
GIT_REPO.sdk=		https://github.com/dart-lang/sdk.git
WRKSRC=			${WRKDIR}/sdk

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dartlang.org/
COMMENT=	Programming language for building web, server, and mobile apps
LICENSE=	modified-bsd

REPLACE_PYTHON+=		tools/build.py

do-build:
	${RUN} cd ${WRKSRC} && ./tools/build.py -m release -a x64

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
