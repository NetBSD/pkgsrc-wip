# $NetBSD: Makefile,v 1.4 2011/02/25 09:47:50 thomasklausner Exp $
#

DISTNAME=	wicd-1.6.2.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wicd/}

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://wicd.sourceforge.net/
COMMENT=	Wired and Wireless network manager for Linux
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.10:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-dbus>=0.80:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-urwid>=0.9.9:../../devel/py-urwid

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24
PY_PATCHPLIST = YES
PYSETUP = setup.py

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_TOOLS+=	intltool

RCD_SCRIPTS=	wicd
RCD_SCRIPT_SRC.wicd=	${FILESDIR}/wicd.sh

# Adjust setup.py
SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_MESSAGE.setup=	Fixing ${PYSETUP}
SUBST_FILES.setup=	${PYSETUP}
SUBST_SED.setup+=	-e 's,/etc/,${PREFIX}/etc/,g'
SUBST_SED.setup+=	-e 's,/usr/lib/,${PREFIX}/lib/,g'
SUBST_SED.setup+=	-e 's,/usr/share/man/,${PKGMANDIR}/,g'
SUBST_SED.setup+=	-e 's,/usr/share/,${PREFIX}/share/,g'
SUBST_SED.setup+=	-e 's,/usr/bin/,${PREFIX}/bin/,g'
SUBST_SED.setup+=	-e 's,/usr/sbin/,${PREFIX}/sbin/,g'
SUBST_SED.setup+=	-e 's,/usr/bin/python,${PYTHONBIN},g'

ONLY_FOR_PLATFORM= Linux-*-*

do-configure:
	cd ${WRKSRC}; \
	${PYTHONBIN} ${PYSETUP} configure \
				--no-install-init \
				--no-install-acpi \
				--no-install-pmutils \
				--no-install-kde \
			        --distro FAIL

post-install:
	${INSTALL_DATA} ${FILESDIR}/wicd.conf ${PKG_SYSCONFDIR}/dbus-1/system.d/

.include "options.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
