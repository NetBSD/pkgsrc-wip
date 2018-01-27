# $NetBSD: Makefile,v 1.2 2013/03/03 19:46:48 othyro Exp $
#

DISTNAME=	lilyterm-0.9.9.4
CATEGORIES=	x11
MASTER_SITES=	http://lilyterm.luna.com.tw/file/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lilyterm.luna.com.tw/
COMMENT=	Terminal emulator based off of libvte
LICENSE=	gnu-gpl-v3

#DEPENDS+=		valgrind-[0-9]*:../../devel/valgrind

HAS_CONFIGURE=		yes
USE_LANGUAGES+=		c
USE_TOOLS+=		gawk gmake msgfmt pkg-config printf
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/lilyterm.conf ${PKG_SYSCONFDIR}/${PKGBASE}/lilyterm.conf
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/${PKGBASE} ${EGDIR}

.include "options.mk"

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/lilyterm.conf \
		${DESTDIR}${EGDIR}/lilyterm.conf

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/lilyterm.conf

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
