# $NetBSD: Makefile,v 1.1.1.1 2005/01/08 19:22:34 airhead Exp $
#

DISTNAME=		hpoj-0.91
CATEGORIES=		wip print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hpoj/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		airhead@users.sourceforge.net
HOMEPAGE=		http://hpoj.sourceforge.net/
COMMENT=		"HP OfficeJet Linux driver; printing, scanning, and photo-card access"

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--prefix="${PREFIX}" \
			--with-cups-backend \
			--without-snmp \
			--without-qt

REPLACE_PERL+=		${WRKSRC}/scripts/ptal-init
REPLACE_PERL+=		${WRKSRC}/scripts/ptal-init.in

#.include "../../print/cups/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
