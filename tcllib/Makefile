# $NetBSD: Makefile,v 1.7 2005/01/11 21:49:33 ppostma Exp $
#

DISTNAME=		tcllib-1.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
NO_BUILD=		yes

SUBST_CLASSES=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,@FETCH_CMD@,${FETCH_CMD},g"
SUBST_MESSAGE.fix=	"Fixing hardcoded ftp binary"

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig | ${XARGS} ${RM}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
