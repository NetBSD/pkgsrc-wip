# $NetBSD: Makefile,v 1.4 2010/08/27 22:30:04 gregoire Exp $
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
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ARGS= --sysconfdir=${PKG_SYSCONFDIR} \
		--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
		--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
		--enable-dbus-build=false

REPLACE_PYTHON=	base/magic.py
REPLACE_PERL=	prnt/filters/hpcac prnt/hpijs/foomatic-rip-hplip

PY_PATCHPLIST=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
