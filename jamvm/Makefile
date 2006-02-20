# $NetBSD: Makefile,v 1.8 2006/02/20 11:51:20 poppnk Exp $
#

DISTNAME=		jamvm-1.4.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jamvm/}
PKGREVISION=		2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jamvm.sourceforge.net/
COMMENT=		Compact Java Virtual Machine

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-classpath-install-dir=${PREFIX}/
USE_TOOLS+=	gmake

DEPENDS+=	classpath-0.19:../../lang/classpath

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.	if ${MACHINE_ARCH} == "i386"
MACHINE_GNU_PLATFORM=i686-pc-linux-gnu
.	endif
.endif
.if ${OPSYS} == "NetBSD"
MACHINE_GNU_PLATFORM=${MACHINE_ARCH}-foo-openbsd
.endif

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
