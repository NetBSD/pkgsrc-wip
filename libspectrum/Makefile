# $NetBSD: Makefile,v 1.2 2003/08/29 10:31:22 thomasklausner Exp $

DISTNAME=	libspectrum-0.1.1
PKGNAME=	${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www.srcf.ucam.org/~pak21/spectrum/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~pak21/spectrum/libspectrum.html
COMMENT=	ZX Spectrum emulator file format library

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
