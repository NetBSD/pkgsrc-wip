# $NetBSD$

DISTNAME=	senpai-v0.1.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	chat
MASTER_SITES=	-https://git.sr.ht/~taiite/senpai/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~taiite/senpai/archive/
COMMENT=	Modern terminal IRC client
LICENSE=	isc

INSTALLATION_DIRS=	bin
GO_BUILD_PATTERN=	./...

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/senpai \
		${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
