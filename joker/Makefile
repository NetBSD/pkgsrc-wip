# $NetBSD$

DISTNAME=		joker-1.3.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=candid82/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://joker-lang.org/
COMMENT=		A small dialect of Clojure and Clojure(Script) linter.
LICENSE=		epl-v1.0

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/joker ${DESTDIR}${PREFIX}/bin

# .include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
