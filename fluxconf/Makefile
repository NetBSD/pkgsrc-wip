# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 03:30:20 xtraeme Exp $
#

DISTNAME=	fluxconf-0.9.4
CATEGORIES=	wm
MASTER_SITES=	http://devaux.fabien.free.fr/flux/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	pttp://devaux.fabien.free.fr/flux/
COMMENT=	GTK based configuration tool for the fluxbox window manager

BUILD_USES_MSGFMT=	yes
DEPENDS+=		fluxbox-[0-9]*:../../wm/fluxbox

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
