# $NetBSD: Makefile,v 1.13 2015/11/09 11:05:44 nros Exp $
#

DISTNAME=	i3-4.13
CATEGORIES=	wm
MASTER_SITES=	https://i3wm.org/downloads/
EXTRACT_SUFX=	.tar.bz2

GIT_REPOSITORIES=	i3
GIT_REPO.i3=		https://github.com/i3/i3.git
GIT_BRANCH.i3=		next
WRKSRC=			${WRKDIR}/i3

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	https://i3wm.org/
COMMENT=	Improved dynamic tiling window manager
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake bison lex yacc pkg-config perl
USE_TOOLS+=	autoconf autoreconf automake
USE_LANGUAGES=	c99

BUILD_DIRS+=	${MACHINE_GNU_PLATFORM}

PKG_SYSCONFSUBDIR=	i3
INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/${PKGBASE}

EGDIR=		${PREFIX}/share/examples/i3
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/config.keycodes ${PKG_SYSCONFDIR}/config.keycodes

MAKE_FLAGS+=	i3confdir=${EGDIR}

REPLACE_PERL+=	i3-dmenu-desktop
REPLACE_PERL+=	i3-migrate-config-to-v4
REPLACE_PERL+=	i3-save-tree

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-install
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		i3-dmenu-desktop
SUBST_SED.fix-paths+=		-e 's,/usr/local/share,${PREFIX}/share,g'

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
# for i3-save-tree
DEPENDS+=	p5-AnyEvent-I3-[0-9]*:../../wip/p5-AnyEvent-I3

pre-configure:
	cd ${WRKSRC} && autoreconf -i

post-install:
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
.include "../../wip/xcb-util-xrm-git/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
