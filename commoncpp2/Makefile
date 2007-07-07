# $NetBSD: Makefile,v 1.6 2007/07/07 08:06:55 othyro Exp $
#

DISTNAME=		commoncpp2-1.5.3
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gnu.org/gnu/commonc++/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://cplusplus.sourceforge.net/
COMMENT=		Portable and highly optimized class framework for C++

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=         c c++
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccgnu2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libccext2.pc.in
GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
