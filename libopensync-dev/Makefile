# $NetBSD: Makefile,v 1.1 2013/02/24 13:41:22 othyro Exp $
#

DISTNAME=	libopensync-0.39
PKGNAME=	${DISTNAME:S/-/-dev-/1}
CATEGORIES=	comms
#MASTER_SITES=	http://www.opensync.org/download/releases/0.39/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.opensync.org/
COMMENT=	Platform independent, general purpose, synchronization framework
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	libopensync-[0-9]*

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libopensync.pc.in

.include "options.mk"

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
