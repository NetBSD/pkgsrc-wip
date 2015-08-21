# $NetBSD: Makefile,v 1.4 2015/08/21 14:58:49 khorben Exp $
# TODO:
# - move bokken to bin/bokken
# - fix path to bokken.py in bin/bokken

DISTNAME=	bokken-1.8
CATEGORIES=	wip
MASTER_SITES=	https://inguma.eu/attachments/download/212/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://bokken.re/
COMMENT=	Open Source Reverse Code Engineering
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

REPLACE_PYTHON=	bokken.py lib/web/utils.py ui/xdot.py
REPLACE_SH=	bokken

INSTALLATION_DIRS=	share/bokken

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/bokken

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gtksourceview/buildlink3.mk"
.include "../../wip/py-pygraphviz/buildlink3.mk"
.include "../../wip/py-radare2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
