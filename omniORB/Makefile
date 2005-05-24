# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:14 rillig Exp $
#

DISTNAME=		omniORB-4.0.4
CATEGORIES=		devel corba
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omniorb/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://omniorb.sourceforge.net/
COMMENT=		omniORB is an ORB that implements the 2.6 specification of the CORBA

MAKEFILE=		GNUmakefile
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Note: not sure if it is required though
USE_LIBTOOL=	YES

# omniORB requires native threads support
PTHREAD_OPTS=	require native

OMNIORB_ETCDIR?= ${PKG_SYSCONFDIR}
OMNIORB_CONFIG=	${OMNIORB_ETCDIR}/omniORB.cfg

CONFIGURE_ARGS+= --with-omniORB-config=${OMNIORB_CONFIG}
#CONFIGURE_ARGS+= --with-omniNames-logdir=
#CONFIGURE_ARGS+= --with-openssl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/omniORB/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/omniORB/omniORB
	${INSTALL_DATA} ${WRKSRC}/sample.cfg ${PREFIX}/share/examples/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/omniORB/* ${PREFIX}/share/doc/omniORB/omniORB/
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1/

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
