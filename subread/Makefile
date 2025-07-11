# $NetBSD$

DISTNAME=	${PKGNAME}-source
PKGNAME=	subread-2.1.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=subread/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://subread.sourceforge.net/
COMMENT=	High-performance read alignment, quantification and mutation discovery
LICENSE=	gnu-gpl-v3

# Subread is designed to issue a warning if free memory is below 3 GiB.
# It currently does not build on NetBSD due to the lack of libsysinfo.
# We could add NetBSD-specific code, but it would be a better use
# of time to port libsysinfo to NetBSD since it's useful for other apps.
# The libsysinfo package is only for SunOS at the time of this writing.
# FreeBSD has a libsysinfo port that may serve as a model for NetBSD.
NOT_FOR_PLATFORM+=	NetBSD-*-*

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/subread-${PKGVERSION_NOREV}-source/src

CFLAGS+=	-fcommon
MAKE_FILE=	${FILESDIR}/Makefile.pkg
INSTALL_TARGET=	install-strip

.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/libsysinfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
