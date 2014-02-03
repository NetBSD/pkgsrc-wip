# $NetBSD: Makefile,v 1.2 2014/02/03 10:04:24 othyro Exp $
#

DISTNAME=	v0.20.0
PKGNAME=	libgit2-${DISTNAME:S/v//1}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libgit2/libgit2/archive/
DIST_SUBDIR=	${PKGBASE}
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libgit2.github.com/
COMMENT=	Portable, pure C implementation of the Git core methods
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libgit2-0.20.0/libgit2.pc.in

.include "../../lang/python/pyversion.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
