# $NetBSD: Makefile,v 1.6 2003/07/14 16:24:59 xtraeme Exp $
#

DISTNAME=	tsclient-0.120
CATEGORIES=	net
MASTER_SITES=	http://www.gnomepro.com/tsclient/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.gnomepro.com/tsclient/
COMMENT=	GNOME2 Frontend for rdesktop

DEPENDS+=       rdesktop-[0-9]*:../../net/rdesktop
DEPENDS+=       vncviewer-[0-9]*:../../net/vncviewer
DEPENDS+=	gnome2-dirs>=1.1:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes

.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
