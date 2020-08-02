# $NetBSD$

DISTNAME=	clipmenu-6.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=cdown/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/cdown/clipmenu/
COMMENT=	Clipboard management using dmenu
LICENSE=	public-domain

NO_BUILD=	yes

USE_TOOLS+=	bash:run

DEPENDS+=	clipnotify-[0-9]*:../../wip/clipnotify
DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu
DEPENDS+=	xsel-[0-9]*:../../x11/xsel

REPLACE_BASH+=	clipctl
REPLACE_BASH+=	clipdel
REPLACE_BASH+=	clipfsck
REPLACE_BASH+=	clipmenu
REPLACE_BASH+=	clipmenud
REPLACE_BASH+=	tests/test-clipmenu
REPLACE_BASH+=	tests/test-perf

CLIPMENU_SCRIPTS+=	clipctl
CLIPMENU_SCRIPTS+=	clipdel
CLIPMENU_SCRIPTS+=	clipmenu
CLIPMENU_SCRIPTS+=	clipmenud

INSTALLATION_DIRS=	bin share/doc/clipmenu

do-install:
.for s in ${CLIPMENU_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${s} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/clipmenu

.include "../../mk/bsd.pkg.mk"
