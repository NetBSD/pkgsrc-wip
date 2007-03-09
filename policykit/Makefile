# $NetBSD: Makefile,v 1.1.1.1 2007/03/09 08:23:56 ondratu Exp $
#

DISTNAME=	PolicyKit-20060821
CATEGORIES=	sysutils
MASTER_SITES=	ftp://www.blackmouse.biz/policykit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.marcuscom.com/downloads/
COMMENT=	Framework for defining policy for system-wide components

# docbook-doc needs xmlto, and thats crash on Linux :(
#BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
CONFIGURE_ARGS+=		--disable-docbook-docs

# i'm not sure which pams are acceptable
#PAM_ACCEPTED=		linux-pam

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

USE_LANGUAGES+=		c c++

POLKID_USER?=		polkit
POLKID_GROUP?=		polkit

PKG_GROUPS=		${POLKID_GROUP}
PKG_USERS=		${POLKID_USER}:${POLKID_GROUP}
BUILD_DEFS+=		POLKID_USER POLKID_GROUP

CONFIGURE_ARGS+=	--with-os-type=${LOWER_VENDOR}
CONFIGURE_ARGS+=	--with-polkit-user=${POLKID_USER}
CONFIGURE_ARGS+=	--with-polkit-group=${POLKID_GROUP}
CONFIGURE_ARGS+=	--with-pam-module-dir=${PAM_INSTMODULEDIR}
CONFIGURE_ARGS+=	--with-pid-file=/var/run/polkitd.pid
CONFIGURE_ARGS+=	--localstatedir=/var


PKGCONFIG_OVERRIDE+=	polkit.pc.in

RCD_SCRIPTS+=		polkitd

DBUS_DIR=		${PKG_SYSCONFDIR}/dbus-1
PAM_DIR=		${PKG_SYSCONFDIR}/pam

MAKE_DIRS=		${PKG_SYSCONFDIR}/PolicyKit/privilege.d

EGDIR=			${PREFIX}/share/examples/policykit
CONF_FILES=		${EGDIR}/desktop-console.privilege ${PKG_SYSCONFDIR}/PolicyKit/privilege.d/desktop-console.privilege
CONF_FILES+=		${EGDIR}/PolicyKit.conf ${DBUS_DIR}/system.d/PolicyKit.conf
CONF_FILES+=		${EGDIR}/policy-kit ${PAM_DIR}/policy-kit

WRKSRC=			${WRKDIR}/PolicyKit


.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/PAM/module.mk"
.include "../../mk/bsd.pkg.mk"
