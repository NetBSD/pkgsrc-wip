# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:19 othyro Exp $
#

DISTNAME=		goldwater-1.4.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.zxdesign.info/download/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.zxdesign.info/download/src/
COMMENT=		Highly scalable distributed middleware

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/phlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
