# $NetBSD: Makefile,v 1.15 2015/06/26 21:40:14 othyro Exp $
#

DISTNAME=	sipwitch-1.9.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=sipwitch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/sipwitch/
COMMENT=	Secure peer-to-peer VoIP server that uses the SIP protocol
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libsipwitch.pc.in

.include "options.mk"

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-configure
SUBST_MESSAGE.files=	Fixing paths and permissions.
SUBST_FILES.files=	cmake_install.cmake server/cmake_install.cmake
SUBST_SED.files+=	-e 's|SETUID|SETUID OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE|1'

CFLAGS+=	-fPIC
CMAKE_ARGS+=	-DINSTALL_LIBDIR:STRING=lib -DINSTALL_MANDIR:STRING=${PKGMANDIR}
SPECIAL_PERMS+=	bin/sippasswd ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4555

EGDIR=			share/examples/sipwitch
INSTALLATION_DIRS+=	${EGDIR}/sipwitch.d

CONF_FILES+=	${EGDIR}/sipwitch.conf ${PKG_SYSCONFDIR}/sipwitch.conf
CONF_FILES+=	${EGDIR}/sipwitch.d/lab.xml-example ${PKG_SYSCONFDIR}/sipwitch.d/lab.xml-example
CONF_FILES+=	${EGDIR}/sipwitch.d/tests.xml ${PKG_SYSCONFDIR}/sipwitch.d/tests.xml

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/sipwitch.conf
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/sipwitch.d/*
	${INSTALL_DATA} ${WRKSRC}/server/sipwitch.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/sipwitch.conf
	${INSTALL_DATA} ${WRKSRC}/server/lab.xml-example \
		${DESTDIR}${PREFIX}/${EGDIR}/sipwitch.d/lab.xml-example
	${INSTALL_DATA} ${WRKSRC}/server/tests.xml \
		${DESTDIR}${PREFIX}/${EGDIR}/sipwitch.d/tests.xml

.include "../../net/libexosip/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.avahi+=	avahi>=0.3.0
.include "../../net/avahi/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.ucommon+=	ucommon>=6.3.1
.include "../../devel/ucommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
