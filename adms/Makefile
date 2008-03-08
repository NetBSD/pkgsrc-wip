# $NetBSD: Makefile,v 1.3 2008/03/08 20:07:58 hoka_adam Exp $
#

DISTNAME=		adms-2.2.8
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mot-adms/}
SUBDIR+=		adms

MAINTAINER=		10.50@free.fr
HOMEPAGE=		http://mot-adms.sourceforge.net/
COMMENT=		Verilog to C code compiler

#PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison flex autoconf
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++ fortran

#LDFLAGS+= ${COMPILER_RPATH_FLAG}${PREFIX}/lib

pre-configure:
	cd ${WRKSRC} && autoconf	

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
