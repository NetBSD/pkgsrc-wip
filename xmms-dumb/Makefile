# $NetBSD: Makefile,v 1.12 2010/12/25 12:45:45 noud4 Exp $
#

DISTNAME=		dumb-xmms-0.1
PKGREVISION=		2
PKGNAME=		${DISTNAME:S/dumb-xmms/xmms-dumb/}
WRKSRC=			${WRKDIR}/dumb-xmms
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dumb/}

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://dumb.sourceforge.net/
COMMENT=		XMMS mod player plugin based on dumb

USE_TOOLS+=		gmake

.include "../../wip/dumb/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
