# $NetBSD: Makefile,v 1.4 2004/11/27 14:03:20 poppnk Exp $
#

DISTNAME=		bluez-utils-2.11
CATEGORIES=		wip net
MASTER_SITES=		http://bluez.sf.net/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Linux Bluetooth Stack utilities

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

EGDIR=${PKG_SYSCONFDIR}/bluetooth/
CONF_FILES=${EGDIR}/hcid.conf ${EGDIR}/rfcomm.conf

SUBST_CLASSES+=initd
SUBST_STAGE.initd=pre-install
SUBST_FILES.initd=scripts/Makefile
SUBST_SED.initd=-e 's,install-data-local,,g'

.include "../../wip/bluez-libs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
