# $NetBSD: Makefile,v 1.1 2014/12/02 23:59:29 thomasklausner Exp $

DISTNAME=		scim-0.0
CATEGORIES=		math
MASTER_SITES=		https://github.com/andmarti1424/scim/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/andmarti1424/scim/
COMMENT=		Text-mode spreadsheet

GIT_REPOSITORIES=	scim
GIT_REPO.scim= 		git://github.com/andmarti1424/scim.git
WRKSRC=			${WRKDIR}/scim

USE_TOOLS+=		bison gmake
BUILD_DIRS=		src

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
