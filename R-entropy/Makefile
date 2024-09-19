# $NetBSD: Makefile,v 1.9 2013/11/22 11:41:46 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://strimmerlab.org/software/entropy/
COMMENT=	Estimation of Entropy, Mutual Information and Related Quantities
LICENSE=	gnu-gpl-v3

R_PKGNAME=	entropy
R_PKGVER=	1.2.1

BUILDLINK_API_DEPENDS.R+=	R>=2.15.1

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
