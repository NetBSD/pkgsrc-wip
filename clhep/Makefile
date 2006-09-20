# $NetBSD: Makefile,v 1.2 2006/09/20 19:55:59 rillig Exp $
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
USE_TOOLS+=	aclocal autoconf automake gmake perl

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${EXTRACT_DIR}/configure
USE_LANGUAGES=		c c++

pre-configure:
	mkdir ${WRKSRC}
	cd ${EXTRACT_DIR}	\
	&& autoconf		\
	&& aclocal		\
	&& automake -a --foreign -i

.include	"../../mk/bsd.pkg.mk"
