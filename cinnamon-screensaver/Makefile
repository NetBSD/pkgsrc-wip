# $NetBSD: Makefile,v 1.2 2015/02/19 18:01:20 jihbed Exp $

DISTNAME=	cinnamon-screensaver-3.8.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cinnamon-screensaver
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@gmail.com
HOMEPAGE=	https://github.com/linuxmint/cinnamon-screensaver
COMMENT=	Cinnamon screensaver
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config automake autoreconf intltool msgfmt

PLIST_VARS+=	pam

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=        --disable-pam
.else
PLIST.pam=		yes
CONFIGURE_ARGS+=	--with-pam-prefix=/etc/pam.d \
			--without-systemd

DEPENDS+=	pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid

INSTALLATION_DIRS+=	${PREFIX}/share/examples/pam.d
post-extract:
	        ${CP} ${FILESDIR}/cinnamon-screensaver.pam ${WRKDIR}

SUBST_CLASSES+=		pam-conf
SUBST_STAGE.pam-conf=	post-configure
SUBST_FILES.pam-conf=	${WRKDIR}/cinnamon-screensaver.pam
SUBST_VARS.pam-conf=	PREFIX

post-install: pamd
.PHONY: pamd
pamd:
	        ${TEST} -f ${DESTDIR}${PREFIX}/share/examples/pam.d/cinnamon-screensaver || \
		${INSTALL_DATA} ${WRKDIR}/cinnamon-screensaver.pam ${DESTDIR}${PREFIX}/share/examples/pam.d/cinnamon-screensaver

MAKE_DIRS+=	/etc/pam.d
CONF_FILES+=	${PREFIX}/share/examples/pam.d/cinnamon-screensaver \
		/etc/pam.d/cinnamon-screensaver
.endif

BUILD_DEPENDS+=		gettext-m4>=0.14.6:../../devel/gettext-m4
BUILD_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive

DEPENDS+=	${PYPKGPREFIX}-xapp>=1.2.0:../../wip/py-xapp
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle


REPLACE_PYTHON=	"screensavers/xscreensaver@cinnamon.org/main"		\
		"screensavers/xscreensaver@cinnamon.org/safechild"	\
		"screensavers/webkit@cinnamon.org/main"			\
		"src/cinnamon-screensaver-command.py"			\
		"src/cinnamon-screensaver-main.py"
pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"

.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../wip/xapps/buildlink3.mk"

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
