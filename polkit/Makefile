# $NetBSD: Makefile,v 1.1 2015/01/01 07:45:49 obache Exp $
#

DISTNAME=	polkit-0.103
CATEGORIES=	security
MASTER_SITES=	http://www.freedesktop.org/software/polkit/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/polkit
COMMENT=	Authorization Manager
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config intltool gmake msgfmt

PKGCONFIG_OVERRIDE+=	data/polkit-backend-1.pc.in
PKGCONFIG_OVERRIDE+=	data/polkit-gobject-1.pc.in
PKGCONFIG_OVERRIDE+=	data/polkit-agent-1.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/polkit

# avoid to conflict with sysutils/policykit
post-install:
	${MV} -f ${DESTDIR}${PREFIX}/libexec/polkitd ${DESTDIR}${PREFIX}/libexec/polkitd-1

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/polkit-1/localauthority \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700
OWN_DIRS_PERMS+=	${VARBASE}/lib/polkit-1 \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700
SPECIAL_PERMS+=		libexec/polkit-agent-helper-1 ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		bin/pkexec ${SETUID_ROOT_PERMS}
.for d in 90-mandatory.d 50-local.d 30-site.d 20-org.d 10-vendor.d
OWN_DIRS+=	${PKG_SYSCONFDIR}/polkit-1/localauthority/${d}
OWN_DIRS+=	${VARBASE}/polkit-1/localauthority/${d}
.endfor
OWN_DIRS+=	${PKG_SYSCONFDIR}/polkit-1

CONF_FILES+=	${PREFIX}/share/examples/polkit/dbus-1/system.d/org.freedesktop.PolicyKit1.conf	\
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.PolicyKit1.conf
OWN_DIRS+=	${PKG_SYSCONFDIR}/polkit-1/localauthority.conf.d
CONF_FILES+=	${PREFIX}/share/examples/polkit/polkit-1/localauthority.conf.d/50-localauthority.conf \
		${PKG_SYSCONFDIR}/polkit-1/localauthority.conf.d/50-localauthority.conf
OWN_DIRS+=	${PKG_SYSCONFDIR}/polkit-1/nullbackend.conf.d
CONF_FILES+=	${PREFIX}/share/examples/polkit/polkit-1/nullbackend.conf.d/50-nullbackend.conf \
		${PKG_SYSCONFDIR}/polkit-1/nullbackend.conf.d/50-nullbackend.conf

BUILD_DEFS+=	VARBASE

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
