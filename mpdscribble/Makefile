# $NetBSD: Makefile,v 1.1.1.1 2007/03/04 20:25:14 guigui2 Exp $
#

DISTNAME=	mpdscribble-0.2.12
CATEGORIES=	audio
MASTER_SITES=	http://www.frob.nl/projects/scribble/

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://www.frob.nl/projects/scribble/
COMMENT=	Mpdscribble is a music player daemon client

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../audio/libmpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
