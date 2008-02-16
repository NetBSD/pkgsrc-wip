# $NetBSD: Makefile,v 1.12 2008/02/16 23:02:24 shattered Exp $
#

DISTNAME=	gajim-0.11.4
CATEGORIES=	chat python
MASTER_SITES=	http://www.gajim.org/downloads/

MAINTAINER=	vsevolod@highsecure.ru
HOMEPAGE=	http://www.gajim.org/
COMMENT=	Jabber client written in PyGTK

DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "options.mk"

PY_PATCHPLIST=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gmake intltool pkg-config
GNU_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Makefile src/common/Makefile
SUBST_SED.paths=	-e 's,/usr/include,${LOCALBASE}/include,g'

SUBST_CLASSES+=		pythonbin
SUBST_STAGE.pythonbin=	pre-configure
SUBST_FILES.pythonbin=	src/roster_window.py
SUBST_SED.pythonbin=	-e 's,@PYTHONBIN@,${PYTHONBIN},'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/gajim-remote.py src/gajim.py src/common/configpaths.py \
	src/gtkgui_helpers.py src/roster_window.py
SUBST_VARS.prefix=	PREFIX

SUBST_CLASSES+=		abs
SUBST_STAGE.abs=	pre-configure
SUBST_FILES.abs=	src/*.py src/common/*.py
SUBST_SED.abs=		-e 's,^GTKGUI_GLADE.*,GTKGUI_GLADE = "${PREFIX}/share/gajim/src/gtkgui.glade",'
SUBST_SED.abs+=		-e "s,'\\.\\./data,'${PREFIX}/share/gajim/data,g"

PYTHON_PATCH_SCRIPTS+=	src/gajim.py src/history_manager.py src/gajim-remote.py

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-lXss
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/gajim.py ${PREFIX}/bin/gajim
.if !empty(PKG_OPTIONS:Mdbus)
	${INSTALL_SCRIPT} ${WRKSRC}/src/gajim-remote.py ${PREFIX}/bin/gajim-remote
.endif
	cd ${WRKSRC} && \
	for i in `find data/emoticons data/iconsets -iname\
	'*.jpg' -o -iname '*.png' -o -iname '*.py'` ;\
	do\
	    ${INSTALL_DATA_DIR} `${DIRNAME} ${PREFIX}/share/gajim/$$i` ;\
            ${INSTALL_DATA} $$i ${PREFIX}/share/gajim/$$i ;\
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
