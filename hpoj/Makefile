# $NetBSD: Makefile,v 1.2 2005/01/10 19:30:15 domg Exp $
#

DISTNAME=		hpoj-0.91
CATEGORIES=		wip print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hpoj/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		domg@users.sourceforge.net
HOMEPAGE=		http://hpoj.sourceforge.net/
COMMENT=		"HP OfficeJet Linux driver; printing, scanning, and photo-card access"

# Add this DEPENDS for killall command
DEPENDS+=       psmisc[0-9]*:../../sysutils/psmisc

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
			--with-cups-backend=${PREFIX}/libexec/cups \
			--with-sane-backend=${PREFIX}/lib/sane \
			--with-sane-etc=${PREFIX}/etc/sane.d \
 			--with-usb=libusb \
			--without-snmp \
			--without-qt

REPLACE_PERL+=		${WRKSRC}/scripts/ptal-init
REPLACE_PERL+=		${WRKSRC}/scripts/ptal-init.in

.include "../../print/cups/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
