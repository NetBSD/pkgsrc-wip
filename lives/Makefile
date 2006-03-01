# $NetBSD: Makefile,v 1.1.1.1 2006/03/01 21:56:58 poppnk Exp $
#

DISTNAME=		LiVES-0.9.6-pre2
PKGNAME=		lives-0.9.6-pre2
CATEGORIES=		wip multimedia
MASTER_SITES=		http://www.xs4all.nl/%7Esalsaman/lives/current/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://lives.sf.net/
COMMENT=		Linux Video Editing System

DEPENDS+= mplayer>=1.0:../../multimedia/mplayer
DEPENDS+= mencoder>=1.0:../../multimedia/mencoder

WRKSRC=		${WRKDIR}/lives-0.9.6-pre2
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
