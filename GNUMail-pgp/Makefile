# $NetBSD: Makefile,v 1.2 2008/01/18 04:30:10 tnn2 Exp $
#

PKGNAME=	GNUMail-pgp-1.1.2
DISTNAME=	GNUMail-1.1.2
PKGREVISION=	1
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
