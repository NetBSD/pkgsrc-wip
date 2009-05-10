# $NetBSD: Makefile,v 1.11 2009/05/10 23:24:25 othyro Exp $
#

DISTNAME=		commoncpp2-1.7.3
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gnu.org/gnu/commonc++/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://cplusplus.sourceforge.net/
COMMENT=		Portable and highly optimized class framework for C++

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccgnu2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccext2.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ENV+=		ac_cv_lib_rt_clock_gettime=no
CONFIGURE_ENV+=		ac_cv_func_clock_gettime=no
INFO_FILES=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
