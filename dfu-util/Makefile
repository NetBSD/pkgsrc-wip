# $NetBSD: Makefile,v 1.6 2012/06/14 23:42:45 othyro Exp $
#

DISTNAME=		dfu-util-4412
CATEGORIES=		comms
MASTER_SITES=		http://wiki.openmoko.org/
SVN_REPOSITORY=		https://svn.openmoko.org/trunk/src/host/dfu-util/
NO_CHECKSUM=		yes

MAINTAINER=		noud4@home.nl
HOMEPAGE=		http://wiki.openmoko.org/wiki/Dfu-util
COMMENT=		Host side of the USB DFU protocol
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
BUILD_DEPENDS+=		subversion-base>=1.4.2:../../devel/subversion-base

SUBDIR=			${PKGNAME}
WRKSRC=	${WRKDIR}/${SUBDIR}
USE_TOOLS+=		autoconf automake tar
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	-prefix=${PREFIX}
CFLAGS+=		-lusb

do-fetch:
	if [ ! -f ${DISTDIR}/${SUBDIR:Q}.tar.gz ]; then \
		cd ${DISTDIR:Q}; \
		svn export -r ${PKGVERSION} ${SVN_REPOSITORY} ${SUBDIR:Q}; \
		tar -czf ${SUBDIR:Q}.tar.gz ${SUBDIR:Q}; \
		${RM} -r ${DISTDIR}/${SUBDIR:Q}; \
	fi

pre-configure:
	${CHMOD} u+x ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
