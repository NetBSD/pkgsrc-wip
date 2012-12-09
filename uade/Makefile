# $NetBSD: Makefile,v 1.8 2012/12/09 15:34:45 othyro Exp $
#

DISTNAME=	uade-2.13
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.fi/uade/uade2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zakalwe.fi/uade/
COMMENT=	Unix Amiga Delitracker Emulator
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-text-scope

.include "options.mk"

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
