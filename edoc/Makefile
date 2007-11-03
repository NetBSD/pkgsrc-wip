# $NetBSD: Makefile,v 1.2 2007/11/03 11:31:10 bjcosta Exp $
#

# Created using instructions from:
# http://www.netbsd.org/docs/pkgsrc/creating.html

DISTNAME=		edoc-0.1.0
CATEGORIES=		devel
MASTER_SITES=		http://downloads.sourceforge.net/edoc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		brendon@christian.net
HOMEPAGE=		http://edoc.sourceforge.net/index.html
COMMENT=		Compile time C++ exception analysis/documentation tool

USE_TOOLS+=		gmake
USE_TOOLS+=		perl

USE_LIBTOOL=		yes

#@@@Brendon Fortran should not be used but requested that i add it as the
# configure script seems to check for f77
USE_LANGUAGES=		c c++ fortran



USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDoc/EDoc.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDoc/EDoc-ver.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDocPy/EDocPy.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDocPy/EDocPy-ver.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDocBFD/EDocBFD-ver.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libs/EDocBFD/EDocBFD.pc.in
GNU_CONFIGURE=		yes


# Some of the linux dependencies I may need to add.
# python2.4-dev, binutils-dev, texinfo, libltdl3-dev, libc6-dev, g++
#.include "../../lang/python24/buildlink3.mk"
PYTHON_VERSIONS_INCOMPATIBLE=	 15 20 21 22 23
.include "../../lang/python/pyversion.mk"

# Bring libbfd.
.if !exists(/usr/include/bfd.h)
USE_BUILTIN.binutils=no
.endif
.include "../../devel/binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
