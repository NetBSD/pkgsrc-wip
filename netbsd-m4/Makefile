# $NetBSD: Makefile,v 1.5 2008/03/30 13:26:25 cheusov Exp $
#

DISTNAME=	netbsd-m4-3.1
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
#${MASTER_SITE_SOURCEFORGE:=netbsd-tools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of M4

PKG_DESTDIR_SUPPORT=    user-destdir
USE_FEATURES=		nbcompat
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

MAKE_ENV+=		MKCATPAGES=no

post-patch:
	sed -e 's|m4|nbm4|g' ${WRKSRC}/m4.1 > ${WRKSRC}/nbm4.1

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
	    -f ${MAKE_FILE} ${BUILD_TARGET} LDADD=${LIBS:Q}

do-install:
	${INSTALL_MAN} ${WRKSRC}/nbm4.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/m4 ${DESTDIR}${PREFIX}/bin/nbm4

.include "../../mk/bsd.pkg.mk"
