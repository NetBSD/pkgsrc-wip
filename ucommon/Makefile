# $NetBSD: Makefile,v 1.9 2013/04/04 11:05:08 thomasklausner Exp $
#

DISTNAME=	ucommon-6.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=commonc++/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/commoncpp/
COMMENT=	Very light-weight C++ library for deeply embedded applications
LICENSE=	gnu-gpl-v3

#BUILD_DEPENDS+=	doxygen>=1.6.2:../../devel/doxygen

USE_TOOLS+=	intltool pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DINSTALL_MANDIR=${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	commoncpp.pc.in
PKGCONFIG_OVERRIDE+=	ucommon.pc.in

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
