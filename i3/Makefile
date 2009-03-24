# $NetBSD: Makefile,v 1.3 2009/03/24 14:04:23 mstapelberg Exp $
#

PKGNAME=	i3-3a
DISTNAME=	i3-3.a
CATEGORIES=	wm
MASTER_SITES=	http://i3.zekjur.net/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael+pkgsrc@stapelberg.de
HOMEPAGE=	http://i3.zekjur.net/
COMMENT=	Improved dynamic tiling window manager

USE_TOOLS+=		gmake
BUILD_DEPENDS+=		asciidoc>=8.3.0:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto:../../textproc/xmlto
BUILD_DEPENDS+=		docbook-xml:../../textproc/docbook-xml
PKG_DESTDIR_SUPPORT=	user-destdir

CONF_FILES=${PREFIX}/share/doc/i3/config ${PKG_SYSCONFDIR}/i3/config

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing absolute paths (installation)
SUBST_FILES.fix-prefix=		Makefile
SUBST_SED.fix-prefix=		-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.fix-prefix+=		-e 's,/etc/i3,${PREFIX}/share/doc/i3,g'

SUBST_CLASSES+=		fix-src
SUBST_STAGE.fix-src=	pre-configure
SUBST_MESSAGE.fix-src=	Fixing absolute paths (source)
SUBST_FILES.fix-src=	src/config.c
SUBST_SED.fix-src=	-e 's,/etc/i3,${PREFIX}/etc/i3,g'

post-build:
	cd ${WRKSRC} && gmake -C man

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/i3.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/xcb-util/buildlink3.mk"
.include "../../wip/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
