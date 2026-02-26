# $NetBSD$

DISTNAME=	aml-1.0.0
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=any1/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/any1/aml/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/${DISTNAME}

# -D_POSIX_C_SOURCE=200809L
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE=1

PKGCONFIG_OVERRIDE+=		output/meson-private/aml1.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
