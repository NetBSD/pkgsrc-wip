# $NetBSD: Makefile,v 1.8 2013/05/21 11:46:25 obache Exp $
#

DISTNAME=	CRF++-0.58
PKGNAME=	${DISTNAME:tl:S/+/p/g}
CATEGORIES=	textproc
MASTER_SITES=	http://crfpp.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/crfpp
COMMENT=	Yet Another CRF toolkit
LICENSE=	gnu-lgpl-v2.1 OR 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PTHREAD_AUTO_VARS=	yes
SUBST_CLASSES+=			pthread_flags
SUBST_STAGE.pthread_flags=	pre-configure
SUBST_FILES.pthread_flags=	configure
SUBST_SED.pthread_flags=	-e 's/-lpthread/${PTHRAD_LIBS} ${PTHREAD_LDFLAGS}/'
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
