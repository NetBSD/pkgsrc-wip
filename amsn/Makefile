# $NetBSD: Makefile,v 1.11 2004/11/01 15:03:16 ppostma Exp $
#

DISTNAME=		amsn-0_93
PKGNAME=		${DISTNAME:S/_/./}
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=		virtus@wanadoo.nl
HOMEPAGE=		http://amsn.sourceforge.net/
COMMENT=		"Alvaro's MSN messenger client"

USE_BUILDLINK3=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

SUBST_CLASSES=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	amsn
SUBST_SED.fix=		-e 's!@@PREFIX@@!${PREFIX}!g'

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig | ${XARGS} ${RM}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/amsn
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/amsn
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	${CP} -R ${WRKSRC}/icons/32x32/* ${PREFIX}/share/pixmaps
	${LN} -sf ${PREFIX}/share/amsn/amsn ${PREFIX}/bin/amsn
	${CHMOD} +x ${PREFIX}/share/amsn/amsn

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
