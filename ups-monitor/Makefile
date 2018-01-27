# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:52 thomasklausner Exp $

DISTNAME=		ups-monitor-0.8.3
CATEGORIES=		sysutils
MASTER_SITES=		http://rudd-o.com/uploads/projects/files/ups-monitor/

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://rudd-o.com/projects/ups-monitor/	# XXX page not found
COMMENT=		Display UPS information in real time
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake
REPLACE_PYTHON=		ups-monitor
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ORBit via py-gnome2

SUBST_CLASSES+=		py
SUBST_STAGE.py=		post-patch
SUBST_FILES.py=		eggtray/Makefile.in
SUBST_SED.py=		-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|"
SUBST_MESSAGE.py=	Fixing Python version.

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	eggtray/Makefile.in
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|"
SUBST_MESSAGE.prefix=	Fixing prefix.

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
