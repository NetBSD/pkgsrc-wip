# $NetBSD: Makefile,v 1.2 2005/03/07 14:57:31 dillo Exp $
#

DISTNAME=		git-104
CATEGORIES=		games
MASTER_SITES=		http://diden.net/if/git/releases/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://diden.net/if/git/
COMMENT=		Interprter for Glulx interactive fiction

WRKSRC=			${WRKDIR}/git-1.0.4
USE_BUILDLINK3=		yes
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

.include "../../wip/glkloader/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
