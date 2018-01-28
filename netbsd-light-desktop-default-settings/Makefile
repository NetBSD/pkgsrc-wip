# $NetBSD: Makefile,v 1.8 2013/02/01 01:38:00 jeremy-c-reed Exp $
#

DISTNAME=	netbsd-light-desktop-default-settings-0.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
# TODO: point to wiki for this package
HOMEPAGE=	http://wiki.NetBSD.org/
COMMENT=	Default settings for NetBSD Light Desktop
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	lightdm-gtk-greeter>=0:../../wip/lightdm-gtk-greeter
DEPENDS+=	lxsession>=0:../../x11/lxsession
DEPENDS+	netbsd-icon-theme>=0:../../wip/netbsd-icon-theme
DEPENDS+=	netbsd-light-desktop-artwork>=0:../../wip/netbsd-light-desktop-artwork
DEPENDS+=	pcmanfm>=0.5:../../wip/pcmanfm

NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOL+=	pax

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/lxsession/NetBSD
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/lxsession/NetBSD-Netbook
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/pcmanfm/netbsd-light-desktop
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/menus
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/lxdm
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/libfm
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/applications

EGDIR=		${PREFIX}/share/examples/netbsd-light-desktop
CONF_FILES+=	${EGDIR}/xdg/lxsession/NetBSD/desktop.conf \
		${PKG_SYSCONFDIR}/xdg/lxsession/NetBSD/desktop.conf
CONF_FILES+=	${EGDIR}/xdg/lxsession/NetBSD/autostart \
		${PKG_SYSCONFDIR}/xdg/lxsession/NetBSD/autostart
CONF_FILES+=	${EGDIR}/xdg/lxsession/NetBSD-Netbook/desktop.conf \
		${PKG_SYSCONFDIR}/xdg/lxsession/NetBSD-Netbook/desktop.conf
CONF_FILES+=	${EGDIR}/xdg/lxsession/NetBSD-Netbook/autostart \
		${PKG_SYSCONFDIR}/xdg/lxsession/NetBSD-Netbook/autostart
CONF_FILES+=	${EGDIR}/xdg/pcmanfm/netbsd-light-desktop/pcmanfm.conf \
		${PKG_SYSCONFDIR}/xdg/pcmanfm/netbsd-light-desktop/pcmanfm.conf
CONF_FILES+=	${EGDIR}/xdg/netbsd-light-desktop/menus/lxde-applications.menu \
		${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/menus/lxde-applications.menu
CONF_FILES+=	${EGDIR}/xdg/netbsd-light-desktop/lxdm/lxdm.conf \
		${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/lxdm/lxdm.conf
CONF_FILES+=	${EGDIR}/xdg/netbsd-light-desktop/libfm/libfm.conf \
		${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/libfm/libfm.conf
CONF_FILES+=	${EGDIR}/xdg/netbsd-light-desktop/applications/defaults.list \
		${PKG_SYSCONFDIR}/xdg/netbsd-light-desktop/applications/defaults.list

do-extract:
	${MKDIR} -p ${WRKSRC}
	@${CP} -R ${FILESDIR}/* ${WRKSRC}

do-configure:
	${FIND} ${WRKSRC} -type f -print | while read fn ; do \
		mv $${fn} $${fn}.orig ; \
		sed -e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g' \
			-e 's,@PREFIX@,${PREFIX},g' < $${fn}.orig > $${fn} ; \
	done
	${CHMOD} 755 ${WRKSRC}/bin/*

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd  ${WRKSRC} &&	\
	pax -rw -s ',.*/CVS.*,,' -s ',.*.orig$$,,' bin share ${DESTDIR}${PREFIX}/
	cd  ${WRKSRC}/etc &&	\
	pax -rw -s ',.*/CVS.*,,' -s ',.*.orig$$,,' xdg \
		${DESTDIR}${PREFIX}/share/examples/netbsd-light-desktop/

#         ttf-ubuntu-font-family
#Recommends: amixer,
#            scrot,
#            galculator


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
