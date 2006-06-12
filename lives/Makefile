# $NetBSD: Makefile,v 1.2 2006/06/12 16:47:12 thomasklausner Exp $
#

DISTNAME=		LiVES-0.9.6-pre2
PKGNAME=		lives-0.9.6pre2
CATEGORIES=		multimedia
MASTER_SITES=		http://www.xs4all.nl/%7Esalsaman/lives/current/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://lives.sf.net/
COMMENT=		Linux Video Editing System

DEPENDS+=	mplayer>=1.0rc1:../../multimedia/mplayer
DEPENDS+=	mencoder>=1.0rc1:../../multimedia/mencoder

WRKSRC=		${WRKDIR}/lives-0.9.6-pre2
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
