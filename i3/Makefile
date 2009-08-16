# $NetBSD: Makefile,v 1.8 2009/08/16 15:38:31 thomasklausner Exp $
#

PKGNAME=	i3-3b
DISTNAME=	i3-3.b
CATEGORIES=	wm
MASTER_SITES=	http://i3.zekjur.net/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael+pkgsrc@stapelberg.de
HOMEPAGE=	http://i3.zekjur.net/
COMMENT=	Improved dynamic tiling window manager

BUILD_DEPENDS+=		asciidoc>=8.3.0:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=		docbook-xml-[0-9]*:../../textproc/docbook-xml

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

INSTALLATION_DIRS=${PKG_SYSCONFDIR}/i3 ${PKGMANDIR}/man1
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
SUBST_SED.fix-src=	-e 's,/etc/i3,${PKG_SYSCONFDIR}/i3,g'

post-build:
	cd ${WRKSRC} && gmake -C man

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/i3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libev/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
