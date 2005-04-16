# $NetBSD: Makefile,v 1.5 2005/04/16 12:31:13 thomasklausner Exp $
#

DISTNAME=		git-110
PKGNAME=		git-1.1.0
CATEGORIES=		games
MASTER_SITES=		http://diden.net/if/git/releases/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://diden.net/if/git/
COMMENT=		Interpreter for Glulx interactive fiction

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

.include "../../wip/glkloader/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
