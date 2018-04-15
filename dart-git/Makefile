# $NetBSD$

DISTNAME=	sdk-1.13.0
PKGNAME=	${DISTNAME:S,sdk,dart,}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=dart-lang/}
GITHUB_PROJECT=	sdk

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dartlang.org/
COMMENT=	Programming language for building web, server, and mobile apps
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	Linux-*-* Darwin-*-*

PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON+=		tools/build.py

do-build:
	${RUN} cd ${WRKSRC} && ./tools/build.py -m release -a x64

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
