# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:08 thomasklausner Exp $
#

DISTNAME=	hplip-3.10.2
PKGREVISION=	1
CATEGORIES=	wip
MASTER_SITES=	http://downloads.sourceforge.net/project/hplip/hplip/3.10.2/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://downloads.sourceforge.net/project/hplip/hplip/3.10.2/
COMMENT=	HP Linux imaging and printing
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ARGS= --sysconfdir=${PKG_SYSCONFDIR} \
		--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--enable-dbus-build=false

.include "../../lang/python/application.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
