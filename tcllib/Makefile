# $NetBSD: Makefile,v 1.3 2004/06/13 18:21:24 ppostma Exp $
#

DISTNAME=		tcllib-1.6.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
NO_BUILD=		yes

PKGVERSION=		1.6 # XXX

post-patch:
	@${MV} ${WRKSRC}/modules/doctools/mpformats/_html.tcl \
		${WRKSRC}/modules/doctools/mpformats/_html.sed
	@${SED} -e "s,@FETCH_CMD@,${FETCH_CMD}," \
		${WRKSRC}/modules/doctools/mpformats/_html.sed > \
		${WRKSRC}/modules/doctools/mpformats/_html.tcl
	@${RM} ${WRKSRC}/modules/doctools/mpformats/_html.sed
	@${FIND} ${WRKSRC} -name \*.orig | ${XARGS} ${RM}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
