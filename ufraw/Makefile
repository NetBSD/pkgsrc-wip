# $NetBSD: Makefile,v 1.2 2005/03/14 21:17:47 lexort Exp $

DISTNAME=	ufraw-0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.aei.mpg.de/~udif/UFRaw/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=	Fancy GIMP plugin for dcraw (digital camera raw file decoder)

# Each plugin claims .nef, so they can't coexist.
CONFLICTS+=	rawphoto

USE_BUILDLINK3=	yes

USE_GNU_TOOLS+=	make
BUILD_TARGET=	build
INSTALL_TARGET=	install-admin

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
