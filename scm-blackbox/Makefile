# $NetBSD$

PKGNAME=	scm-blackbox-1.20181219
DISTNAME=	blackbox-1.20181219
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=StackExchange/}
GITHUB_PROJECT=	blackbox
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/StackExchange/blackbox
COMMENT=	Safely store secrets in Git/Mercurial/Subversion
LICENSE=	mit

USE_TOOLS+=	bash

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

REPLACE_BASH+=	bin/*blackbox*

INSTALLATION_DIRS+= bin
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/_stack_lib.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*blackbox* ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
