# $NetBSD: Makefile,v 1.1.1.1 2005/01/04 02:17:44 lexort Exp $

DISTNAME=	ufraw-0.2
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
.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
