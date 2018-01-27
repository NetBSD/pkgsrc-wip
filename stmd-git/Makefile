# $NetBSD: Makefile,v 1.1 2014/09/04 10:21:07 thomasklausner Exp $

DISTNAME=		stmd-1.0
CATEGORIES=		textproc
MASTER_SITES=		https://github.com/jgm/stmd

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/jgm/stmd
COMMENT=		Standard markdown converter implementation
LICENSE=		modified-bsd

GIT_REPOSITORIES=	stmd
GIT_REPO.stmd=		git://github.com/jgm/stmd.git

BUILD_DEPENDS+=		re2c-[0-9]*:../../devel/re2c

WRKSRC=			${WRKDIR}/stmd
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin share/doc/stmd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stmd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/spec.txt ${DESTDIR}${PREFIX}/share/doc/stmd

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
