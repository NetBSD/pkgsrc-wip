# $NetBSD: Makefile,v 1.1.1.1 2004/05/23 23:22:32 dillo Exp $
#

DISTNAME=		git-104
CATEGORIES=		zzz
MASTER_SITES=		http://diden.net/if/git/releases/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://diden.net/if/git/
COMMENT=		Interprter for Glulx interactive fiction

WRKSRC=			${WRKDIR}/git-1.0.4
USE_BUILDLINK3=		yes
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

.include "../../wip/gtkglk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
