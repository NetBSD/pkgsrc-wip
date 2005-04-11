# $NetBSD: Makefile,v 1.5 2005/04/11 21:13:03 tvierling Exp $
#

DISTNAME=		hpoj-0.91
CATEGORIES=		wip print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hpoj/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		domg@users.sourceforge.net
HOMEPAGE=		http://hpoj.sourceforge.net/
COMMENT=		HP OfficeJet Linux driver; printing, scanning, and photo-card access

# Add this DEPENDS for killall command
DEPENDS+=       psmisc-[0-9]*:../../sysutils/psmisc
# The ptal-cups script require bash
DEPENDS+=	bash-[0-9]*:../../shells/bash

USE_GNU_TOOLS+=		make
USE_PERL5=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
			--with-cups-backend=${PREFIX}/libexec/cups/backend \
			--with-sane-backend=${PREFIX}/lib/sane \
			--with-sane-etc=${PREFIX}/etc/sane.d \
 			--with-usb=libusb \
			--without-snmp \
			--without-qt

REPLACE_PERL+=		scripts/ptal-init.in
REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	.*/bin/bash
_REPLACE.bash.new=	${PREFIX}/bin/bash
_REPLACE_FILES.bash=	scripts/ptal-cups.in

.include "../../print/cups/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
