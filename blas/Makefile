# $NetBSD$

# This is just a dummy to pull in Netlib BLAS from lapack.

# Should the version be kept in sync with lapack?
# The main point of this package is a smooth transition
# until everyone uses mk/blas.buildlink3.mk (and people removed
# math/blas from their pkgsrc-related scripts).

PKGNAME=	blas-3.8.0
PKGREVISION=	1
CATEGORIES=	math
COMMENT=	Transitional BLAS package that depends on lapack

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	http://www.netlib.org/lapack/
LICENSE=	modified-bsd

META_PACKAGE=	yes

.include "../lapack/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

