# $NetBSD$

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command Line Option Parser
LICENSE=	gnu-gpl-v2

R_PKGNAME=	optparse
R_PKGVER=	1.7.5

DEPENDS+=	R-getopt>=1.20.2:../../wip/R-getopt

REPLACE_R=	exec/example.R exec/display_file.R

REPLACE_INTERPRETER+=	R
REPLACE.R.old=		/usr/bin/env Rscript
REPLACE.R.new=		${PREFIX}/bin/R
REPLACE_FILES.R=	${REPLACE_R}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
