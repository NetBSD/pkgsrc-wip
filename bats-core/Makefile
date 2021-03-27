# $NetBSD$

DISTNAME=		bats-core-1.3.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=bats-core/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		iku.iwasa@gmail.com
HOMEPAGE=		https://github.com/bats-core/bats-core
COMMENT=		Bash Automated Testing System
LICENSE=		mit

CONFLICTS+=		bats-[0-9]*

USE_LANGUAGES=		# none

NO_BUILD=		yes
USE_TOOLS+=		bash:run

REPLACE_BASH+=		bin/bats libexec/bats-core/*

SUBST_CLASSES+=		fixsh
SUBST_STAGE.fixsh=	pre-configure
SUBST_MESSAGE.fixsh=	Enable function import
SUBST_FILES.fixsh=	bin/bats libexec/bats-core/*
SUBST_SED.fixsh+=	-e '1s,^\#!.*,& --import-functions,'

do-install:
	cd ${WRKSRC} && ${SETENV} PKGMANDIR=${PKGMANDIR} ./install.sh ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ./bin/bats ./test

.include "../../mk/bsd.pkg.mk"
