# $NetBSD: Makefile,v 1.1.1.1 2012/03/02 20:26:08 outpaddling Exp $
#

DISTNAME=	arpack96
PKGNAME=	arpack-96
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	arpack96.tar.gz patch.tar.gz

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://www.caam.rice.edu/software/ARPACK/SRC/
COMMENT=	TODO: Short description of the package
LICENSE=	original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ARPACK
USE_LANGUAGES=	fortran

MAKE_ENV+=	WRKSRC=${WRKSRC}

USE_TOOLS+=	gmake gsed tar
TOOLS_PLATFORM.gsed=	#empty

# Patches must be extracted AFTER the main dist to overwrite files
post-extract:
	(cd ${WRKDIR} && ${TAR} zxf ${DISTDIR}/patch.tar.gz)

post-patch:
	sed -i'' -e 's|$$(HOME)/ARPACK|${WRKSRC}|g' ${WRKSRC}/ARmake.inc

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libarpack.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
