# $NetBSD: Makefile,v 1.7 2015/08/21 15:26:59 khorben Exp $

DISTNAME=	bokken-1.8
CATEGORIES=	wip
MASTER_SITES=	https://inguma.eu/attachments/download/212/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://bokken.re/
COMMENT=	Open Source Reverse Code Engineering
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax

NO_BUILD=	yes

REPLACE_PYTHON=	bokken.py lib/web/utils.py ui/xdot.py
REPLACE_SH=	bokken

SUBST_CLASSES+=			bin-bokken
SUBST_STAGE.bin-bokken=		post-patch
SUBST_MESSAGE.bin-bokken=	Fixing path to bokken.py
SUBST_FILES.bin-bokken=		bokken
SUBST_SED.bin-bokken=	-e 's,`dirname $$0`,"${PREFIX}/share/bokken",'

INSTALLATION_DIRS=	bin share/bokken

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/bokken
	${RM} ${DESTDIR}${PREFIX}/share/bokken/.gitignore
	${MV} ${DESTDIR}${PREFIX}/share/bokken/bokken ${DESTDIR}${PREFIX}/bin/bokken

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gtksourceview/buildlink3.mk"
.include "../../graphics/py-pygraphviz/buildlink3.mk"
.include "../../devel/py-radare2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
