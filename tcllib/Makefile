# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 16:24:29 xtraeme Exp $
#

DISTNAME=		tcllib-1.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

post-patch:
	@${MV} ${WRKSRC}/modules/doctools/mpformats/_html.tcl \
		${WRKSRC}/modules/doctools/mpformats/_html.sed
	@${SED} -e "s,@PREFIX@,${PREFIX}," \
		${WRKSRC}/modules/doctools/mpformats/_html.sed > \
		${WRKSRC}/modules/doctools/mpformats/_html.tcl
	@${RM} ${WRKSRC}/modules/doctools/mpformats/_html.sed
	@${FIND} ${WRKSRC} -name \*.orig | ${XARGS} ${RM}

.include "../../lang/tcl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
