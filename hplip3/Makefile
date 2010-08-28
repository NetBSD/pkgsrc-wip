# $NetBSD: Makefile,v 1.8 2010/08/28 01:41:45 gregoire Exp $
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

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++ fortran
USE_TOOLS+=	autoconf automake gmake pkg-config

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR} \
		--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter

REPLACE_PYTHON=	base/magic.py
REPLACE_PERL=	prnt/filters/hpcac prnt/hpijs/foomatic-rip-hplip

PY_PATCHPLIST=	yes

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-configure
SUBST_MESSAGE.fix-paths=Fixing absolute paths.
SUBST_FILES.fix-paths=	*.py */*.py */*/*.py prnt/*/*.cpp
SUBST_FILES.fix-paths+=	prnt/hpijs/foomatic-rip-hplip
SUBST_FILES.fix-paths+=	fax/filters/pstotiff
SUBST_SED.fix-paths=	-e 's,\([ '\''";]\)/etc/hp,\1${PKG_SYSCONFDIR}/hp,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/etc/cups,\1${PKG_SYSCONFDIR}/cups,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/etc/foomatic,\1${PKG_SYSCONFDIR}/foomatic,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/etc/sane.d,\1${PKG_SYSCONFDIR}/sane.d,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/etc/dbus-1,\1${PKG_SYSCONFDIR}/dbus-1,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/usr/lib/cups,\1${PREFIX}/libexec/cups,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/usr/local,\1${PREFIX},g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/usr/share/cups,\1${PREFIX}/share/cups,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/usr/share/ppd,\1${PREFIX}/share/ppd,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/usr/share/dbus-1,\1${PREFIX}/share/dbus-1,g'
SUBST_SED.fix-paths+=	-e 's,\([ '\''";]\)/usr/share/hal,\1${PREFIX}/share/hal,g'

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

pre-configure:
	cd ${WRKSRC} && aclocal && automake --add-missing --foreign && autoconf

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
