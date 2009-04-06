# $NetBSD: Makefile,v 1.2 2009/04/06 20:41:07 jihbed Exp $
#

DISTNAME=	dragbox-0.4.0
CATEGORIES=	misc gnome
MASTER_SITES=	http://kaizer.se/publicfiles/dragbox/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://users.student.lth.se/f04us/wiki/dragbox/
COMMENT=	Command line drag-and-drop tool for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake


REPLACE_PYTHON=+	dragbox
PY_PATCHPLIST=	yes

INSTALLATION_DIRS+= 	share/doc

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dragbox

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
