# $NetBSD: Makefile,v 1.13 2010/01/17 12:03:23 thomasklausner Exp $
#

DISTNAME=		commoncpp2-1.7.3
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gnu.org/gnu/commonc++/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://cplusplus.sourceforge.net/
COMMENT=		Portable and highly optimized class framework for C++
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ENV+=		ac_cv_lib_rt_clock_gettime=no
CONFIGURE_ENV+=		ac_cv_func_clock_gettime=no
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccgnu2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccext2.pc.in
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
