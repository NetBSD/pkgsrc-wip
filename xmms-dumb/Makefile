# $NetBSD: Makefile,v 1.5 2004/01/25 02:33:57 grantbeattie Exp $
#

DISTNAME=		dumb-xmms-0.1
PKGNAME=		${DISTNAME:S/dumb-xmms/xmms-dumb/}
WRKSRC=			${WRKDIR}/dumb-xmms
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net/
COMMENT=		XMMS mod player plugin based on dumb

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../wip/dumb/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
