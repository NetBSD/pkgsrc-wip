# $NetBSD$

GITHUB_PROJECT=	git-extras
GITHUB_TAG=	6.2.0
DISTNAME=	6.2.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tj/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://github.com/tj/git-extras/
COMMENT=	Little git extras
LICENSE=	mit

WRKSRC=		${WRKDIR}/git-extras-6.2.0
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake bash

NO_BUILD=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

DEPENDS+=	bash-[0-9]*:../../shells/bash

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/usr/bin/env bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	bin/*

.include "../../mk/bsd.pkg.mk"
