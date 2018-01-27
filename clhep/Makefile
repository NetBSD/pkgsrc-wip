# $NetBSD: Makefile,v 1.15 2012/10/14 11:44:38 asau Exp $
#

DISTNAME=	clhep-2.1.2.5
CATEGORIES=	math
MASTER_SITES=	http://proj-clhep.web.cern.ch/proj-clhep/DISTRIBUTION/tarFiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://proj-clhep.web.cern.ch/proj-clhep/
COMMENT=	Class library for high energy physics
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

TMPEXT_DIR=	${WRKDIR}/${PKGVERSION_NOREV}/CLHEP
AUTOCONF_REQD=	2.59
USE_TOOLS+=	aclocal autoconf automake gmake perl

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${TMPEXT_DIR}/configure
USE_LANGUAGES=		c c++

# Apply extra force to make it link on FreeBSD 6.3:
LDFLAGS.FreeBSD=	-lc

pre-configure:
	${RUN} ${MKDIR} ${WRKSRC};	\
	cd ${TMPEXT_DIR};		\
	${CONFIG_SHELL} bootstrap

.include "../../mk/bsd.pkg.mk"
