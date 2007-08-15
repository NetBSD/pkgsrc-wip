# $NetBSD: Makefile,v 1.7 2007/08/15 19:13:31 othyro Exp $
#

DISTNAME=		commoncpp2-1.5.3
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gnu.org/gnu/commonc++/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://cplusplus.sourceforge.net/
COMMENT=		Portable and highly optimized class framework for C++

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=         c c++ fortran
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccgnu2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccext2.pc.in
GNU_CONFIGURE=		yes
INFO_FILES=		yes

INSTALLATION_DIRS=	bin include/cc++2 info lib lib/pkgconfig share/aclocal

do-build:
	cd ${WRKSRC} && ${MAKE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/ccgnu2-config ${PREFIX}/bin/ccgnu2-config
	${INSTALL_DATA_DIR} ${PREFIX}/include/cc++2/cc++
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/libccext2.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/libccgnu2.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/libccext2.pc ${PREFIX}/lib/pkgconfig
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/libccgnu2.pc ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA_DIR} ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/doc/commoncpp2.info ${PREFIX}/info/commoncpp2.info
	${INSTALL_DATA_DIR} ${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/src/ost_check2.m4 ${PREFIX}/share/aclocal/ost_check2.m4
	set -e; \
	cd ${WRKSRC}/include/cc++; \
	for include in *.h; do \
		${INSTALL_DATA} $${include} ${PREFIX}/include/cc++2/cc++/; \
	done;

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
