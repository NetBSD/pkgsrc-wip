# $NetBSD: Makefile,v 1.3 2013/03/19 01:22:55 bubuchka Exp $

CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/web/packages/cellranger/index.html
COMMENT=	Helper functions to work with spreadsheets
LICENSE=	gnu-gpl-v2

R_PKGNAME=	cellranger
R_PKGVER=	1.1.0

DEPENDS+=       R-rematch>=1.0.1:../../wip/R-rematch

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
