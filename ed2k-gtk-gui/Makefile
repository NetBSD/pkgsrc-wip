# $NetBSD: Makefile,v 1.1.1.1 2004/01/08 11:54:06 minskim Exp $
#

DISTNAME=		ed2k-gtk-gui-0.6.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ed2k-gtk-gui/}

MAINTAINER=		minskim@bawi.org
HOMEPAGE=		http://ed2k-gtk-gui.sourceforge.net/
COMMENT=		GUI for the eDonkey2000 and Overnet

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		shell
SUBST_MESSAGE.shell=	"Fixing hardcoded shell."
SUBST_STAGE.shell=	post-patch
SUBST_FILES.shell=	ed2k_gui/misc.c
SUBST_SED.shell=	-e 's,/bin/bash,/bin/sh,g'

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../net/gnet/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
