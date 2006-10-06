# $NetBSD: Makefile,v 1.1 2006/10/06 03:49:32 kcf Exp $
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

# Force builder to set QTDIR
.if !defined (QTDIR)
all:
	@${ECHO} You must set environment variable QTDIR to point to the installation
	@${ECHO}   directory of QT.  For QT3, this is typically '/usr/pkg/qt3'.
.endif

BUILD_DEPENDS+= qt3-tools>=3.3.6:../../x11/qt3-tools

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
