# $NetBSD: Makefile,v 1.1.1.1 2003/05/16 04:17:00 jeremy-c-reed Exp $

DISTNAME=		netkit-base-0.17
CATEGORIES=		net
# sunsite has older 0.16 version
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.hcs.harvard.edu/~dholland/computers/netkit.html
COMMENT=		The inetd super server and ping for Linux

ONLY_FOR_PLATFORM=	Linux-*-*

USE_GMAKE=		YES

DESCR_SRC=		${WRKDIR}/.DESCR_SRC

do-configure:
	cd ${WRKSRC} && \
	${SET_ENV} ${CONFIGURE_ENV} ./configure --prefix=${PREFIX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/netkit-base/etc.sample
	${INSTALL_DATA} ${WRKSRC}/etc.sample/* ${PREFIX}/share/netkit-base/etc.sample
	${SED} 's,@PREFIX@,${PREFIX},' ${PKGDIR}/DESCR > ${DESCR_SRC}

.include "../../mk/bsd.pkg.mk"
