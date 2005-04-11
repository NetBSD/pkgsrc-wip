# $NetBSD: Makefile,v 1.3 2005/04/11 21:12:30 tvierling Exp $
#

DISTNAME=		gnome-bluetooth-0.5.1
CATEGORIES=		wip net
MASTER_SITES=		http://downloads.usefulinc.com/gnome-bluetooth/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://downloads.usefulinc.com/gnome-bluetooth/
COMMENT=		Gnome Bluetooth Manager

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS=	make
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gnome-bluetooth.pc.in
GNU_CONFIGURE=		yes

SUBST_CLASSES= py
SUBST_FILES.py=src/Makefile
SUBST_STAGE.py=post-configure
SUBST_SED.py=-e 's,/usr/share/,${PREFIX}/share/,g' \
		-e 's,python ,python2.3 ,g'

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gob2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../wip/libbtctl/buildlink3.mk"
.include "../../x11/gnome-python/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
