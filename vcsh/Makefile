# $NetBSD$

DISTNAME=	vcsh-1.20151229
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=RichiH/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sasha-pkgsrc@arcocene.org
HOMEPAGE=	https://github.com/RichiH/vcsh/
COMMENT=	Version Control System for the home directory
LICENSE=	gnu-gpl-v2

DEPENDS+=	git-base-[0-9]*:../../devel/git-base
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Shell-Command-[0-9]*:../../wip/p5-Shell-Command
BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../wip/p5-Test-Most
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

USE_LANGUAGES=	c
USE_TOOLS=	perl

.include "../../mk/bsd.pkg.mk"
