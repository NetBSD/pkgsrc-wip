# $NetBSD: Makefile,v 1.15 2010/08/29 10:07:31 gregoire Exp $
#

DISTNAME=	hplip-3.10.6
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hplip/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://hplip.sourceforge.net/
COMMENT=	HP Linux Imaging and Printing
LICENSE=	gnu-gpl-v2 AND mit AND modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	hpijs-[0-9]*

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++ fortran
USE_TOOLS+=	aclocal autoconf automake gmake pkg-config
USE_TOOLS+=	perl:run

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR} \
		--localstatedir=${VARBASE} \
		--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter
CONFIGURE_ARGS+=--enable-hpcups-install
CONFIGURE_ARGS+=--enable-hpijs-install
CONFIGURE_ARGS+=--enable-cups-drv-install
CONFIGURE_ARGS+=--enable-cups-ppd-install
CONFIGURE_ARGS+=--enable-foomatic-drv-install
CONFIGURE_ARGS+=--enable-foomatic-ppd-install
CONFIGURE_ARGS+=--enable-foomatic-rip-hplip-install

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
EGFILES=	hp/hplip.conf cups/pstotiff.convs cups/pstotiff.types \
		xdg/autostart/hplip-systray.desktop

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS+=	localstatedir=${EGDIR}
INSTALL_MAKE_FLAGS+=	systraydir=${EGDIR}/xdg/autostart
INSTALL_MAKE_FLAGS+=	mimedir=${EGDIR}/cups

OWN_DIRS+=		${PKG_SYSCONFDIR}/hp
OWN_DIRS+=		${PKG_SYSCONFDIR}/cups
OWN_DIRS+=		${PKG_SYSCONFDIR}/xdg/autostart
OWN_DIRS+=		${VARBASE}/lib/hp

.for file in ${EGFILES}
CONF_FILES+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
CONF_FILES+=	${EGDIR}/lib/hp/hplip.state ${VARBASE}/lib/hp/hplip.state

REPLACE_PYTHON=	*.py */*.py */*/*.py
REPLACE_PERL=	prnt/filters/hpcac prnt/hpijs/foomatic-rip-hplip

PY_PATCHPLIST=	yes

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-configure
SUBST_MESSAGE.fix-paths=Fixing absolute paths.
SUBST_FILES.fix-paths=	*.py */*.py */*/*.py prnt/*/*.cpp
SUBST_FILES.fix-paths+=	prnt/hpijs/foomatic-rip-hplip
SUBST_FILES.fix-paths+=	fax/filters/pstotiff
SUBST_SED.fix-paths=	-e 's,\([ '\''"=:;]\)/etc/hp,\1${PKG_SYSCONFDIR}/hp,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/etc/cups,\1${PKG_SYSCONFDIR}/cups,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/etc/foomatic,\1${PKG_SYSCONFDIR}/foomatic,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/etc/sane.d,\1${PKG_SYSCONFDIR}/sane.d,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/usr/lib/cups,\1${PREFIX}/libexec/cups,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/usr/local,\1${PREFIX},g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/usr/share/cups,\1${PREFIX}/share/cups,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/usr/share/ppd,\1${PREFIX}/share/ppd,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/usr/share/dbus-1,\1${PREFIX}/share/dbus-1,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/var/lib/hp,\1${VARBASE}/lib/hp,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/var/log/cups,\1${VARBASE}/log/cups,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''"=:;]\)/var/spool/cups,\1${VARBASE}/spool/cups,g'

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

pre-configure:
	cd ${WRKSRC} && aclocal && automake --add-missing --foreign && autoconf

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
