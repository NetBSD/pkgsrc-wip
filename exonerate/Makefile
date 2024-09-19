# $NetBSD$

DISTNAME=	exonerate-2.2.0
CATEGORIES=	biology
MASTER_SITES=	http://ftp.ebi.ac.uk/pub/software/vertebrategenomics/exonerate/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ebi.ac.uk/about/vertebrate-genomics/software/exonerate
COMMENT=	Generic tool for pairwise sequence comparison
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
