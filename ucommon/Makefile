# $NetBSD: Makefile,v 1.3 2011/12/30 01:13:23 othyro Exp $
#

DISTNAME=	ucommon-5.0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=commonc++/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/commoncpp/
COMMENT=	Very light-weight C++ library for deeply embedded applications
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
#DEPENDS+=	doxygen>=doxygen-1.6.2:../../devel/doxygen

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DINSTALL_MANDIR=${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	commoncpp.pc.in
PKGCONFIG_OVERRIDE+=	ucommon.pc.in


.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
