# $NetBSD: Makefile,v 1.2 2012/04/02 19:42:31 outpaddling Exp $
#

PKGNAME=	fvcom-2.7.1
DISTNAME=	sourcecode1
CATEGORIES=	math
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/
COMMENT=	Prognostic coastal ocean circulation model
LICENSE=	fvcom-license

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/FVCOM2.7.1/FVCOM_source

USE_TOOLS+=	make
USE_LANGUAGES=	c fortran

DEPENDS+=	metis>=4.0:../../math/metis

AUTO_MKDIRS=	yes

FETCH_MESSAGE=  "Please download the files"
FETCH_MESSAGE+= "    "${DISTFILES:Q}
FETCH_MESSAGE+= "manually from "${MASTER_SITES:Q}"."

pre-patch:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	${MV} ${WRKDIR}/FVCOM2.7.1/METIS_source ${WRKSRC}

pre-build:
	(cd ${WRKSRC}/METIS_source && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom ${DESTDIR}${PREFIX}/bin

# Current netcdf package missing mod file
# No netcdf support until this is resolved
#.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
