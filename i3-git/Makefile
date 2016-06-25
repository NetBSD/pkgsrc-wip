# $NetBSD: Makefile,v 1.13 2015/11/09 11:05:44 nros Exp $
#

DISTNAME=	i3-${VERSION}
VERSION=	4.12
CATEGORIES=	wm
MASTER_SITES=	http://i3wm.org/downloads/
EXTRACT_SUFX=	.tar.bz2

GIT_REPOSITORIES=	i3
GIT_REPO.i3=		https://github.com/i3/i3.git
GIT_BRANCH.i3=		next
WRKSRC=			${WRKDIR}/i3

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://i3wm.org/
COMMENT=	Improved dynamic tiling window manager
LICENSE=	modified-bsd

USE_TOOLS+=	gmake bison lex yacc pkg-config perl
USE_LANGUAGES=	c99
BUILD_TARGET=	all mans

PKG_SYSCONFSUBDIR=	i3
INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/${PKGBASE}

EGDIR=		${PREFIX}/share/examples/i3
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/config.keycodes ${PKG_SYSCONFDIR}/config.keycodes

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:C/\/i3//}
#MAKE_ENV+=	DEBUG=0
#MAKE_ENV+=	SHM_SUPPORT=0
MAKE_ENV+=	VERSION=${VERSION}

REPLACE_PERL+=	i3-dmenu-desktop
REPLACE_PERL+=	i3-migrate-config-to-v4
REPLACE_PERL+=	i3-save-tree

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_MESSAGE.conf=	Change src/i3.mk to install conf files in share/examples
SUBST_FILES.conf=	src/i3.mk
SUBST_SED.conf=		-e s,$$\(SYSCONFDIR\),$$\(PREFIX\)/share/examples,g

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-install
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		i3-dmenu-desktop
SUBST_SED.fix-paths+=		-e 's,/usr/local/share,${PREFIX}/share,g'

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
# for i3-save-tree
DEPENDS+=	p5-AnyEvent-I3-[0-9]*:../../wip/p5-AnyEvent-I3

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../wip/xcb-util-xrm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
