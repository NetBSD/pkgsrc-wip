# $NetBSD: Makefile,v 1.3 2003/08/29 10:31:22 thomasklausner Exp $

DISTNAME=	fuse-0.6.0
PKGNAME=	${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www.srcf.ucam.org/~pak21/spectrum/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~pak21/spectrum/fuse.html
COMMENT=	ZX Spectrum Emulator

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../x11/gtk/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../libspectrum/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
