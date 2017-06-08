# $NetBSD$

GITHUB_PROJECT=	vcsh
DISTNAME=	v1.20151229
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=RichiH/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	sasha-pkgsrc@arcocene.org
HOMEPAGE=	https://github.com/RichiH/vcsh/
COMMENT=	Version Control System for the home directory
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/vcsh-1.20151229

USE_LANGUAGES=	c
USE_TOOLS=	perl

DEPENDS+=	git-base-[0-9]*:../../devel/git-base
BUILD_DEPENDS+=	p5-Shell-Command-[0-9]*:../../wip/p5-Shell-Command
BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../wip/p5-Test-Most
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

.include "../../mk/bsd.pkg.mk"
