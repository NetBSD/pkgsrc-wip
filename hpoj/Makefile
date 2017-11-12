# $NetBSD: Makefile,v 1.16 2012/09/29 17:05:57 asau Exp $
#

DISTNAME=		hpoj-0.91
PKGREVISION=		4
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hpoj/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		domg@users.sourceforge.net
HOMEPAGE=		http://hpoj.sourceforge.net/
COMMENT=		HP OfficeJet Linux driver; printing, scanning, and photo-card access

# Add this DEPENDS for killall command
DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc
# The ptal-cups script require bash
DEPENDS+=		bash-[0-9]*:../../shells/bash


USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q} \
			--with-cups-backend=${PREFIX:Q}/libexec/cups/backend \
			--with-sane-backend=${PREFIX:Q}/lib/sane \
			--with-sane-etc=${PREFIX:Q}/etc/sane.d \
			--with-usb=libusb \
			--without-snmp \
			--without-qt

REPLACE_PERL+=		scripts/ptal-init.in
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	scripts/ptal-cups.in

.include "../../print/cups-base/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
