# $NetBSD$

# Currently only for SunOS in pkgsrc
# LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

DISTNAME=	subread-2.0.2-source
PKGNAME=	subread-2.0.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=subread/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://bioinf.wehi.edu.au/subread-package/
COMMENT=	High-performance read alignment, quantification and mutation discovery
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/subread-2.0.2-source/src

CFLAGS+=	-fcommon
MAKE_FILE=	${FILESDIR}/Makefile.pkg
INSTALL_TARGET=	install-strip

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
