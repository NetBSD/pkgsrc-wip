# $NetBSD: Makefile,v 1.6 2005/04/11 21:10:20 tvierling Exp $
#

DISTNAME=		bluez-utils-2.15
CATEGORIES=		wip net
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

.include "../../wip/bluez-libs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
