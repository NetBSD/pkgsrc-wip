# $NetBSD: Makefile,v 1.6 2007/09/02 18:19:48 shindenmorr Exp $
#

DISTNAME=	gajim-0.11.1
CATEGORIES=	chat python
MASTER_SITES=	http://www.gajim.org/downloads/

MAINTAINER=	vsevolod@highsecure.ru
HOMEPAGE=	http://www.gajim.org/
COMMENT=	Jabber client written in PyGTK

DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PY_PATCHPLIST=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gmake intltool pkg-config
GNU_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Makefile src/common/Makefile
SUBST_SED.paths=	-e 's,/usr/include,${LOCALBASE}/include,g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/gajim.py src/common/configpaths.py src/gtkgui_helpers.py
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
	cd ${WRKSRC} && \
	for i in `find data/emoticons data/iconsets -iname\
	'*.jpg' -o -iname '*.png' -o -iname '*.py'` ;\
	do\
	    ${INSTALL_SCRIPT_DIR} `${DIRNAME} ${PREFIX}/share/gajim/$$i` ;\
            ${INSTALL_SCRIPT} $$i ${PREFIX}/share/gajim/$$i ;\
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
