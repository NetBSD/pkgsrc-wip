# $NetBSD: Makefile,v 1.5 2006/10/16 20:56:57 kcf Exp $
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

BUILD_DEPENDS+= qt3-tools-3*:../../x11/qt3-tools
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

