# $NetBSD$

DISTNAME=		bats-core-1.12.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=bats-core/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		iquiw@NetBSD.org
HOMEPAGE=		https://github.com/bats-core/bats-core
COMMENT=		Bash Automated Testing System
LICENSE=		mit

CONFLICTS+=		bats-[0-9]*

USE_LANGUAGES=		# none

NO_BUILD=		yes
USE_TOOLS+=		bash:run

REPLACE_BASH+=		bin/bats lib/bats-core/* libexec/bats-core/*

do-install:
	cd ${WRKSRC} && rm -f bin/bats.orig libexec/bats-core/bats.orig && \
		${SETENV} PKGMANDIR=${PKGMANDIR} ./install.sh ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} LC_MESSAGES=C PKGMANDIR=${PKGMANDIR} ./bin/bats ./test

.include "../../mk/bsd.pkg.mk"
