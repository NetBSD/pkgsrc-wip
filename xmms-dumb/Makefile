# $NetBSD: Makefile,v 1.6 2004/05/04 02:47:26 blef Exp $
#

DISTNAME=		dumb-xmms-0.1
PKGNAME=		${DISTNAME:S/dumb-xmms/xmms-dumb/}
WRKSRC=			${WRKDIR}/dumb-xmms
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net/
COMMENT=		XMMS mod player plugin based on dumb

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../wip/dumb/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
