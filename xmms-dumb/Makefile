# $NetBSD: Makefile,v 1.2 2003/07/19 13:45:33 bencollver Exp $
#

DISTNAME=		dumb-xmms-0.1
PKGNAME=		xmms-dumb-0.1
WRKSRC=			${WRKDIR}/dumb-xmms
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net
COMMENT=		XMMS mod player plugin based on dumb

USE_GMAKE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes

.include "../../wip/dumb/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
