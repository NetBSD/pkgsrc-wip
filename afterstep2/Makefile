# $NetBSD: Makefile,v 1.4 2004/10/03 11:33:15 hsaliak Exp $
#

DISTNAME=	AfterStep-2.00.00
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/}
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/
COMMENT=	Window manager based on the look and feel of the NeXTStep interface

PKG_INSTALLATION_TYPES=	 pkgviews overwrite

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PERL5=		run
USE_X11=		YES

INSTALLATION_DIRS=	bin include man/man1 man/man3 share

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
