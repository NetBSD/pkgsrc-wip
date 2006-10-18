# $NetBSD: Makefile,v 1.6 2006/10/18 02:31:34 kcf Exp $
#

BOUMLVERSION=		2.17.1
DISTNAME=		bouml_${BOUMLVERSION}
PKGNAME=		bouml-${BOUMLVERSION}
CATEGORIES=		devel
MASTER_SITES=		http://bouml.free.fr/
MAINTAINER=		kcf@users.sourceforge.net
HOMEPAGE=		http://bouml.free.fr/
COMMENT=		UML modeling tool, generates C++, JAVA, and IDL

USE_LIBTOOL=		YES
USE_LANGUAGES=		c++
BUILD_TARGET=		compile
MAKE_ENV+=		QMAKE="${QTDIR}/bin/qmake"

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

