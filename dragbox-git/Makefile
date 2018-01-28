# $NetBSD: Makefile,v 1.12 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=	dragbox-0.4.0
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://kaizer.se/publicfiles/dragbox/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://users.student.lth.se/f04us/wiki/dragbox/
COMMENT=	Command line drag-and-drop tool for GNOME
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	dragbox
GIT_REPO.dragbox=	git://repo.or.cz/dragbox.git

WRKSRC=		${WRKDIR}/${DISTNAME:S|-${PKGVERSION_NOREV}||}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	autoconf
USE_TOOLS+=	automake

REPLACE_PYTHON+=		dragbox
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ORBit via py-gnome2, py-gtk2, py-gobject

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; automake -a --foreign -i; autoconf

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
