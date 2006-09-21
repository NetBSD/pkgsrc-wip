# $NetBSD: Makefile,v 1.3 2006/09/21 12:50:41 hugor Exp $
#

DISTNAME=	clhep-1.9.2.3
CATEGORIES=	math
MASTER_SITES=	http://cern.ch/clhep/distributions/ \
		http://cern.ch/clhep/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://proj-clhep.web.cern.ch/proj-clhep/
COMMENT=	Class library for high energy physics

EXTRACT_DIR=	${WRKDIR}/1.9.2.3/CLHEP
AUTOCONF_REQD=	2.59
USE_TOOLS+=	automake
USE_TOOLS+=	gmake
USE_TOOLS+=	perl

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ${EXTRACT_DIR}/configure
USE_LANGUAGES+=	c++

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${EXTRACT_DIR}/configure

pre-configure:
	${MKDIR} ${WRKSRC};	\
	cd ${EXTRACT_DIR};	\
	autoconf;	\
	aclocal;	\
	automake -a --foreign -i

.include	"../../mk/bsd.pkg.mk"
