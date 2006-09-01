# $NetBSD: Makefile,v 1.1.1.1 2006/09/01 05:27:32 hugor Exp $
#
DISTNAME=	clhep-1.9.2.3
CATEGORIES=	math
MASTER_SITES=	http://cern.ch/clhep/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hugor@users.sourceforge.net
HOMEPAGE=	http://proj-clhep.web.cern.ch/proj-clhep/
COMMENT=	Class library for high energy physics

EXTRACT_DIR=	${WRKDIR}/1.9.2.3/CLHEP
AUTOCONF_REQD=	2.59
USE_TOOLS+=	automake
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c++

pre-configure:
	${MKDIR} ${WRKSRC};	\
	cd ${EXTRACT_DIR};	\
	autoconf;	\
	aclocal;	\
	automake -a --foreign -i
do-configure:
	cd ${WRKSRC};	\
	${EXTRACT_DIR}/${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}


.include	"../../mk/bsd.pkg.mk"
