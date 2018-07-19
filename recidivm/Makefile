# $NetBSD$

DISTNAME=	recidivm-0.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jwilk/}
GITHUB_RELEASE=	0.1.4

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	http://jwilk.net/software/recidivm
COMMENT=	Estimates a program's peak virtual memory use
LICENSE=	mit

NO_CONFIGURE=			yes
USE_TOOLS+=			gmake

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fix man paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths=		-e 's,/share/man,/man,g'

TEST_TARGET=			test

.include "../../mk/bsd.pkg.mk"
