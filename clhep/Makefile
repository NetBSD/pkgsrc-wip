# $NetBSD: Makefile,v 1.11 2010/01/13 18:01:45 asau Exp $
#

DISTNAME=	clhep-2.0.4.5
CATEGORIES=	math
MASTER_SITES=	http://proj-clhep.web.cern.ch/proj-clhep/DISTRIBUTION/tarFiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://proj-clhep.web.cern.ch/proj-clhep/
COMMENT=	Class library for high energy physics

PKG_DESTDIR_SUPPORT=	user-destdir

TMPEXT_DIR=	${WRKDIR}/${PKGVERSION_NOREV}/CLHEP
AUTOCONF_REQD=	2.59
USE_TOOLS+=	aclocal autoconf automake gmake perl

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ${TMPEXT_DIR}/configure
USE_LANGUAGES=	c c++

pre-configure:
	${RUN} ${MKDIR} ${WRKSRC};	\
	cd ${TMPEXT_DIR};		\
	autoconf;			\
	aclocal;			\
	automake -a --foreign -i

.include "../../mk/bsd.pkg.mk"
