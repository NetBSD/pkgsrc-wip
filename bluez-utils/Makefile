# $NetBSD: Makefile,v 1.12 2006/06/17 15:12:48 poppnk Exp $
#

DISTNAME=		bluez-utils-3.0
CATEGORIES=		net
MASTER_SITES=		http://bluez.sf.net/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Linux Bluetooth Stack utilities

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

EGDIR=${PKG_SYSCONFDIR}/bluetooth/
CONF_FILES=${EGDIR}/hcid.conf ${EGDIR}/rfcomm.conf

SUBST_CLASSES+=initd
SUBST_STAGE.initd=pre-install
SUBST_FILES.initd=scripts/Makefile
SUBST_SED.initd=-e 's,install-data-local,,g'

.include "../../comms/openobex/buildlink3.mk"
.include "../../wip/bluez-libs/Makefile.common"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
