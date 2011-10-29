# $NetBSD: Makefile,v 1.2 2011/10/29 00:58:30 othyro Exp $
#

DISTNAME=	ucommon-5.0.6
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/gnu/commonc++/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.gnu.org/gnu/commonc++/
COMMENT=	Very light-weight C++ library for deeply embedded applications
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
#DEPENDS+=	doxygen>=doxygen-1.6.2:../../devel/doxygen

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DINSTALL_MANDIR=${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	commoncpp.pc.in
PKGCONFIG_OVERRIDE+=	ucommon.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf


.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
