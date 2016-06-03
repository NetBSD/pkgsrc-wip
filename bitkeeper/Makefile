# $NetBSD$

DISTNAME=	bk-7.2.1
PKGNAME=	${DISTNAME:S/bk/bitkeeper/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bitkeeper-scm/}
GITHUB_TAG=	${DISTNAME}ce

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitkeeper.org/
COMMENT=	Distributed Source Control System
LICENSE=	apache-2.0

USE_TOOLS+=	gmake bison lex groff perl bash

BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_LANGUAGES=	c c++ fortran

do-build:
	${RUN} cd ${WRKSRC}/src && ${GMAKE}  # p

.include "../../mk/bsd.pkg.mk"
