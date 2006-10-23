# $NetBSD: Makefile,v 1.10 2006/10/23 03:57:19 kcf Exp $
#

BOUMLVERSION=		2.17.2
DISTNAME=		bouml_${BOUMLVERSION}
PKGNAME=		bouml-${BOUMLVERSION}
CATEGORIES=		devel
MASTER_SITES=		http://bouml.free.fr/
MAINTAINER=		kcf@users.sourceforge.net
HOMEPAGE=		http://bouml.free.fr/
COMMENT=		UML modeling tool, generates C++, JAVA, and IDL

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
USE_LANGUAGES=		c++
BUILD_TARGET=		compile
USE_DIRS+=		xdg-1.3

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
