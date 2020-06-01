# $NetBSD$

GITHUB_PROJECT=	ast
GITHUB_TAG=	2020.0.0
DISTNAME=	2020.0.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=att/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/att/ast/
COMMENT=	Official AT&T release of KornShell 93
LICENSE=	epl-v1.0

USE_TOOLS+=	pkg-config msgfmt
USE_LANGUAGES=	c c++


WRKSRC=	${WRKDIR}/ast-2020.0.0

do-install:
	cp ${WRKSRC}/output/src/cmd/ksh93/ksh 			\
	${DESTDIR}${PREFIX}/bin/ksh93;                          \

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
