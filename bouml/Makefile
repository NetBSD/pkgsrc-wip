# $NetBSD: Makefile,v 1.3 2006/10/12 14:31:07 kcf Exp $
#

BOUMLVERSION=		2.17.1
DISTNAME=		bouml_${BOUMLVERSION}
PKGNAME=		bouml-${BOUMLVERSION}
CATEGORIES=		devel
MASTER_SITES=		http://bouml.free.fr/

MAINTAINER=		kcf@users.sourceforge.net
HOMEPAGE=		http://bouml.free.fr/
COMMENT=		UML modeling tool, generates C++, JAVA, and IDL
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_LANGUAGES=		c++

.if !defined (QTDIR)
all:
	@${ECHO} "Environment variable QTDIR must be set to the root directory"
	@${ECHO} "of Trolltech's framework, QT3.  Useually, this directory is"
	@${ECHO} "'/usr/pkg/qt3'.  Also, you must have the directory"
	@${ECHO} "'QTDIR/bin' in your PATH, and the 'QTDIR/lib directory"
	@${ECHO} "in your LD_LIBRARY_PATH.  See the pkgsrc/x11/qt3-libs/MESSAGE"
	@${ECHO} "file and QT3 documentation for details."
.endif


.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
