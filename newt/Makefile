# $NetBSD: Makefile,v 1.3 2005/03/18 19:30:23 riz Exp $

DISTNAME=		${NEWTNAME}-5.src.rpm
NEWTNAME=		newt-0.51.6
PKGNAME=		${NEWTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://download.fedora.redhat.com/pub/fedora/linux/core/3/SRPMS/
EXTRACT_SUFX=		# empty
PKGREVISION=		1

MAINTAINER=		riz@netbsd.org
HOMEPAGE=		# empty
COMMENT=		Windowing toolkit based on libslang

BUILD_DEPENDS+=		rpm2pkg>=2.0:../../pkgtools/rpm2pkg

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
NO_EXPORT_CPP=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${NEWTNAME}

do-extract:
	rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DISTNAME}
	cd ${WRKDIR} ; ${GZCAT} ${WRKDIR}/${NEWTNAME}.tar.gz | ${TAR} -xf -

do-install:
	cd ${WRKSRC}; \
	 ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} libnewt.la ${PREFIX}/lib;\
	 ${INSTALL_DATA} newt.h ${PREFIX}/include; \
	 ${INSTALL_PROGRAM} .libs/whiptail ${PREFIX}/bin

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
