# $NetBSD: Makefile,v 1.2 2003/12/25 16:21:56 jmmv Exp $
#

DISTNAME=	AfterStep-2.00.beta3
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/:S/.beta/beta/}
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.afterstep.org/devel/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/
COMMENT=	Window manager based on the look and feel of the NeXTStep interface

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		run
USE_X11=		YES

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
