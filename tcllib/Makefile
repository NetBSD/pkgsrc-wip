# $NetBSD: Makefile,v 1.4 2004/06/14 14:07:42 xtraeme Exp $
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

SUBST_CLASSES=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,@FETCH_CMD@,${FETCH_CMD},g"
SUBST_MESSAGE.fix=	"Fixing harcoded ftp binary"

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig | ${XARGS} ${RM}

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
