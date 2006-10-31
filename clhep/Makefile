# $NetBSD: Makefile,v 1.8 2006/10/31 17:01:33 hugor Exp $
#

DISTNAME=	clhep-1.9.3.0
CATEGORIES=	math
MASTER_SITES=	http://cern.ch/clhep/distributions/ \
		http://cern.ch/clhep/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://proj-clhep.web.cern.ch/proj-clhep/
COMMENT=	Class library for high energy physics

TMPEXT_DIR=	${WRKDIR}/1.9.3.0/CLHEP
AUTOCONF_REQD=	2.59
USE_TOOLS+=	aclocal autoconf automake gmake perl

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ${TMPEXT_DIR}/configure
USE_LANGUAGES=	c c++

pre-configure:
	${MKDIR} ${WRKSRC};	\
	cd ${TMPEXT_DIR};	\
	autoconf;	\
	aclocal;	\
	automake -a --foreign -i

.include	"../../mk/bsd.pkg.mk"
