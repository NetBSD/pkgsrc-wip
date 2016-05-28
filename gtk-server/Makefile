# $NetBSD: Makefile,v 1.8 2013/01/01 01:38:05 othyro Exp $
#

DISTNAME=	gtk-server-2.3.1-sr
PKGNAME=	${DISTNAME:S/-sr/sr/1}
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtk-server.org/
COMMENT=	Small tool to enable GUI access for shell scripts
LICENSE=	gnu-gpl-v2


USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
