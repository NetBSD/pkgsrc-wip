# $NetBSD: Makefile,v 1.4 2005/02/28 16:50:04 poppnk Exp $
#

DISTNAME=		bluez-hcidump-1.18
CATEGORIES=		wip net
MASTER_SITES=		http://bluez.sf.net/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.bluez.org/
COMMENT=		Bluetooth packet analyzer

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

DEPENDS+=	bluez-libs>=2.15:../../wip/bluez-libs

.include "../../wip/bluez-libs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
