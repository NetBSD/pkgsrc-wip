# $NetBSD: Makefile,v 1.18 2015/09/13 07:33:05 thomasklausner Exp $

DISTNAME=	crchack-0.0
CATEGORIES=	archivers
GIT_REPO=	https://github.com/resilar/crchack.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/resilar/crchack
COMMENT=	Reversing CRC for fun and profit
LICENSE=	unlicense

USE_LANGUAGES=		c
USE_CC_FEATURES+=	c99
USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin share/doc/crchack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crchack ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/crchack

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
