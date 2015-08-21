# $NetBSD: Makefile,v 1.6 2015/08/21 15:18:00 khorben Exp $
# TODO:
# - fix path to bokken.py in bin/bokken

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

INSTALLATION_DIRS=	bin share/bokken

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/bokken
	${RM} ${DESTDIR}${PREFIX}/share/bokken/.gitignore
	${MV} ${DESTDIR}${PREFIX}/share/bokken/bokken ${DESTDIR}${PREFIX}/bin/bokken

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gtksourceview/buildlink3.mk"
.include "../../wip/py-pygraphviz/buildlink3.mk"
.include "../../wip/py-radare2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
