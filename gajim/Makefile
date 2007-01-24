# $NetBSD: Makefile,v 1.4 2007/01/24 10:10:24 rillig Exp $
#

DISTNAME=	gajim-0.8.2
CATEGORIES=	chat python
MASTER_SITES=	http://www.gajim.org/downloads/

MAINTAINER=	vsevolod@highsecure.ru
HOMEPAGE=	http://www.gajim.org/
COMMENT=	Jabber client written in PyGTK

DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PY_PATCHPLIST=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gmake

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Makefile src/common/Makefile
SUBST_SED.paths=	-e 's,/usr/include,${LOCALBASE}/include,g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/gajim.py
SUBST_VARS.prefix=	PREFIX

SUBST_CLASSES+=		abs
SUBST_STAGE.abs=	pre-configure
SUBST_FILES.abs=	src/*.py src/common/*.py
SUBST_SED.abs=		-e 's,^GTKGUI_GLADE.*,GTKGUI_GLADE = "${PREFIX}/share/gajim/src/gtkgui.glade",'
SUBST_SED.abs+=		-e "s,'\\.\\./data,'${PREFIX}/share/gajim/data,g"

PYTHON_PATCH_SCRIPTS+=	src/gajim.py

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-lXss
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/gajim.py ${PREFIX}/bin/gajim

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
