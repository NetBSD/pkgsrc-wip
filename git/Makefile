# $NetBSD: Makefile,v 1.3 2005/03/07 15:24:21 dillo Exp $
#

DISTNAME=		git-110
PKGNAME=		git-1.1.0
CATEGORIES=		games
MASTER_SITES=		http://diden.net/if/git/releases/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://diden.net/if/git/
COMMENT=		Interprter for Glulx interactive fiction

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

.include "../../wip/glkloader/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
