# $NetBSD: Makefile,v 1.6 2012/07/18 11:14:48 bubuchka Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://strimmerlab.org/software/entropy/
COMMENT=	Entropy and Mutual Information Estimation
LICENSE=	gnu-gpl-v3

R_PKGNAME=	entropy
R_PKGVER=	1.1.7

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
