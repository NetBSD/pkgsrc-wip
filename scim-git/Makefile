# $NetBSD: Makefile,v 1.2 2014/12/03 07:59:39 thomasklausner Exp $

DISTNAME=		scim-0.0
CATEGORIES=		math
MASTER_SITES=		https://github.com/andmarti1424/scim/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/andmarti1424/scim/
COMMENT=		Text-mode spreadsheet

GIT_REPOSITORIES=	scim
GIT_REPO.scim=		git://github.com/andmarti1424/scim.git
WRKSRC=			${WRKDIR}/scim

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		bison gmake
BUILD_DIRS=		src

USE_NCURSES=		yes # set_escdelay()

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
