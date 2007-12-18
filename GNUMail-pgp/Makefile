# $NetBSD: Makefile,v 1.1.1.1 2007/12/18 03:42:43 dvol Exp $
#

PKGNAME=	GNUMail-pgp-1.1.2
DISTNAME=	GNUMail-1.1.2
CATEGORIES=	mail security gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://debian.uni-essen.de/misc/GNUstep/Apps/GNUMail/
COMMENT=	Bundle for PGP support in GNUMail

WRKSRC=		${WRKDIR}/GNUMail/Bundles/PGP

USE_LANGUAGES=	objc
NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

post-extract:
	${RM} -r ${WRKSRC}/*/*/CVS

DEPENDS+=	GNUMail>=1.1.2:../../mail/GNUMail

.include "../../mail/Pantomime/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
