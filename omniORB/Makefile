# $NetBSD: Makefile,v 1.11 2012/10/03 21:32:46 asau Exp $
#

PKGNAME=		omniORB-4.1.2
DISTNAME=		omniORB-4.1.2
CATEGORIES=		devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omniorb/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://omniorb.sourceforge.net/
COMMENT=		OmniORB is an ORB that implements the 2.6 specification of the CORBA

PKG_DESTDIR_SUPPORT=	none

MAKE_FILE=		GNUmakefile
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Note: not sure if it is required though
USE_LIBTOOL=	YES

# omniORB requires native threads support
PTHREAD_OPTS=	require native
RCD_SCRIPTS= 	omninames

OMNIORB_ETCDIR?= ${PKG_SYSCONFDIR}
OMNIORB_CONFIG=	${OMNIORB_ETCDIR}/omniORB.cfg

CONFIGURE_ENV+=  PYTHON=${PYTHONBIN}
CONFIGURE_ARGS+= --with-omniORB-config=${OMNIORB_CONFIG:Q}
#CONFIGURE_ARGS+= --with-omniNames-logdir=
#CONFIGURE_ARGS+= --with-openssl

.include "options.mk"

PY_PATCHPLIST=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/omniORB/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/omniORB/omniORB
	${INSTALL_DATA} ${WRKSRC}/sample.cfg ${PREFIX}/share/examples/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/omniORB/* ${PREFIX}/share/doc/omniORB/omniORB/
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
