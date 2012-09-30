# $NetBSD: Makefile,v 1.16 2012/09/30 05:44:14 asau Exp $
#

DISTNAME=	i3-3.d-bf1
PKGNAME=	${DISTNAME:C/\.//:C/-bf/bf/}
CATEGORIES=	wm
MASTER_SITES=	http://i3.zekjur.net/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael+pkgsrc@stapelberg.de
HOMEPAGE=	http://i3.zekjur.net/
COMMENT=	Improved dynamic tiling window manager

BUILD_DEPENDS+=		asciidoc>=8.3.0:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=		docbook-xml-[0-9]*:../../textproc/docbook-xml

USE_TOOLS+=		bison gmake pkg-config lex yacc

# src/cfgparse.l:11:26: error: cfgparse.tab.h: No such file or directory
MAKE_JOBS_SAFE=		no

PKG_SYSCONFSUBDIR=	i3
INSTALLATION_DIRS=	${PKGMANDIR}/man1
CONF_FILES=	${PREFIX}/share/doc/i3/config ${PKG_SYSCONFDIR}/config

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing absolute paths (installation)
SUBST_FILES.fix-prefix=		Makefile i3-input/Makefile i3-msg/Makefile
SUBST_FILES.fix-prefix+=	i3.config
SUBST_SED.fix-prefix=		-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.fix-prefix+=		-e 's,/etc/i3,${PREFIX}/share/doc/i3,g'

SUBST_CLASSES+=		fix-src
SUBST_STAGE.fix-src=	pre-configure
SUBST_MESSAGE.fix-src=	Fixing absolute paths (source)
SUBST_FILES.fix-src=	src/config.c man/i3.man i3.welcome
SUBST_SED.fix-src=	-e 's,/etc/i3,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-src+=	-e 's,/usr/bin,${PREFIX}/bin,g'

post-build:
	cd ${WRKSRC} && gmake -C man

post-install:
.for i in i3.1 i3-input.1 i3-msg.1
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

.include "../../devel/libev/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
