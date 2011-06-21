# $NetBSD: Makefile,v 1.1.1.1 2011/06/21 17:35:08 othyro Exp $
#

DISTNAME=	ucommon-4.3.3
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/gnu/commonc++/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.gnu.org/gnu/commonc++/
COMMENT=	Very light-weight C++ library for deeply embedded applications
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
#DEPENDS+=	doxygen>=doxygen-1.6.2:../../devel/doxygen

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	commoncpp.pc.in
PKGCONFIG_OVERRIDE+=	ucommon.pc.in

.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
