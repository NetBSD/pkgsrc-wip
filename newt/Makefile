# $NetBSD: Makefile,v 1.1.1.1 2005/02/05 21:42:53 riz Exp $

DISTNAME=		${PKGNAME}-6.src.rpm
PKGNAME=		newt-0.51.6
CATEGORIES=		devel
MASTER_SITES=		http://download.fedora.redhat.com/pub/fedora/linux/core/development/SRPMS/
EXTRACT_SUFX=		# empty

MAINTAINER=		riz@tastylime.net
HOMEPAGE=		# empty
COMMENT=		Windowing toolkit based on libslang

BUILD_DEPENDS+=		rpm2pkg>=2.0:../../pkgtools/rpm2pkg

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
NO_EXPORT_CPP=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME}

do-extract:
	rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DISTNAME}
	cd ${WRKDIR} ; ${GZCAT} ${WRKDIR}/${PKGNAME}.tar.gz | ${TAR} -xf -

do-install:
	cd ${WRKSRC}; \
	 ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} libnewt.la ${PREFIX}/lib;\
	 ${INSTALL_DATA} newt.h ${PREFIX}/include; \
	 ${INSTALL_PROGRAM} .libs/whiptail ${PREFIX}/bin

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
