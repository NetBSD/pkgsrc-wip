# $NetBSD: Makefile,v 1.3 2004/04/25 07:52:40 blef Exp $
#

DISTNAME=	AfterStep-2.00.beta3
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/:S/.beta/beta/}
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.afterstep.org/devel/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/
COMMENT=	Window manager based on the look and feel of the NeXTStep interface

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PERL5=		run
USE_X11=		YES

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
