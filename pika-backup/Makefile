# $NetBSD$

DISTNAME=	pika-backup-v0.3.2
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	https://gitlab.gnome.org/World/pika-backup/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/World/pika-backup/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

.include "cargo-depends.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
