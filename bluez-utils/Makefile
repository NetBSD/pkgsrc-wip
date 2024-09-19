# $NetBSD: Makefile,v 1.18 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=		bluez-utils-3.19
CATEGORIES=		net
MASTER_SITES=		http://bluez.sourceforge.net/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Linux Bluetooth Stack utilities

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

EGDIR=		${PKG_SYSCONFDIR}/bluetooth/
CONF_FILES=	${EGDIR}/hcid.conf ${EGDIR}/rfcomm.conf

SUBST_CLASSES+=		initd
SUBST_STAGE.initd=	pre-install
SUBST_FILES.initd=	scripts/Makefile
SUBST_SED.initd=	-e 's,install-data-local,,g'

.include "../../comms/openobex/buildlink3.mk"
.include "../../wip/bluez-libs/Makefile.common"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
