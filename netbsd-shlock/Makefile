# $NetBSD: Makefile,v 1.1 2008/02/02 13:58:24 cheusov Exp $
#

DISTNAME=	netbsd-shlock-4.0
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of shlock

#USE_FEATURES=	nbcompat

MAKE_ENV+=	MKCATPAGES=no

post-patch:
	sed -e 's|shlock|nbshlock|g' ${WRKSRC}/shlock.1 > ${WRKSRC}/nbshlock.1

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
	    -f ${MAKE_FILE} ${BUILD_TARGET} LDADD=${LIBS:Q}

do-install:
	${INSTALL_MAN} ${WRKSRC}/nbshlock.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/shlock ${PREFIX}/bin/nbshlock

.include "../../mk/bsd.pkg.mk"
