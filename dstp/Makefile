# $NetBSD$

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		dstp-0.4.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=ycd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ycd/dstp/
COMMENT=		Run common networking tests against your site
LICENSE=		mit

USE_LANGUAGES=		# none

.include "go-modules.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/dstp ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
