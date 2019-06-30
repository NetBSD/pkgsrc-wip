# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:36 thomasklausner Exp $
#

DISTNAME=	lightdm-gtk-greeter-1.3.1
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/lightdm-gtk-greeter/1.4/1.3.1/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lightdm-gtk-greeter
COMMENT=	GTK+ greeter for LightDM
LICENSE=	gnu-gpl-v3

# Needed for launchpad

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS=		intltool msgfmt msgmerge perl pkg-config xgettext

EGDIR=		${PREFIX}/share/examples/lightdm
CONF_FILES+=	${EGDIR}/lightdm-gtk-greeter.conf ${PKG_SYSCONFDIR}/lightdm/lightdm-gtk-greeter.conf

INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/lightdm ${EGDIR}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/lightdm-gtk-greeter.conf ${DESTDIR}${EGDIR}/lightdm-gtk-greeter.conf

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/lightdm/lightdm-gtk-greeter.conf


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/lightdm/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
