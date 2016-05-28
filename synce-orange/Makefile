# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:22 asau Exp $
#

DISTNAME=		orange-0.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.synce.org/oldwiki/index.php/Orange
COMMENT=		Extract installable files from self-extracting installers


USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../archivers/unshield/buildlink3.mk"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../wip/synce-dynamite/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
